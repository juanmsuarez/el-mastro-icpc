struct Sum {
    int x; Sum(int _x = 0) { x = _x; }
    Sum operator+(const Sum &o) { return x + o.x; }
};
template <class T>
struct RMQ { // ops O(lg n), [0, n), initial timestamp = 0
    struct Node {
    	T v; Node *l, *r; Node(T x) : v(x), l(0), r(0) {}
        Node(Node *a, Node *b) : l(a), r(b) { v = l->v + r->v; }
    }; 
    int n; vector<T> data; vector<Node*> root;
    RMQ(int sz) : n(sz), data(n) {}
    T& operator[](int p) { return data[p]; }
    void build() { root.pb(build(0, n)); }
    Node* build(int a, int b) {
    	if (a + 1 == b) return new Node(data[a]);
    	int c = (a + b) / 2;
    	return new Node(build(a, c), build(c, b));
    }
    int update(int time, int p, T v) { // copy of seg tree with O(lg n) memory
        root.pb(update(root[time], p, v, 0, n));
        return si(root)-1; // timestamp of new copy
    }
    Node* update(Node *x, int p, T v, int a, int b) {
    	if (a + 1 == b) return new Node(v);
    	int c = (a + b) / 2;
    	if (p < c) return new Node(update(x->l, p, v, a, c), x->r);
        else return new Node(x->l, update(x->r, p, v, c, b));
    }
    T get(int time, int l, int r) { return get(root[time], l, r, 0, n); }
    T get(Node *x, int l, int r, int a, int b) {
        if (r <= a || l >= b) return T();
        if (l <= a && b <= r) return x->v;
        int c = (a + b) / 2;
    	return get(x->l, l, r, a, c) + get(x->r, l, r, c, b);
    }
};
