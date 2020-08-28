typedef int Key;
typedef struct node *pnode;
struct node {
    Key key;
    int prior, size;
    pnode l, r;
    node(Key key = 0): key(key), prior(rand()), size(1), l(0), r(0) {} // usar rand piola
};
static int size(pnode p){ return p ? p->size : 0; }
void push(pnode p){
    // modificar y propagar el dirty a los hijos aca (para lazy)
}
// Update function and size from children's Value
void pull(pnode p){ // recalcular valor del nodo aca (para rmq)
    p->size = 1 + size(p->l) + size(p->r);
}
//junta dos sets 
pnode merge(pnode l, pnode r){
    if(!l || !r) return l ? l : r;
    push(l), push(r);
    pnode t;

    if(l->prior < r->prior) l->r = merge(l->r, r), t = l;
    else r->l = merge(l, r->l), t = r; 

    pull(t);
    return t;
}
//parte el set en dos, l < key <= r
void split(pnode t, Key key, pnode &l, pnode &r){
    if(!t) return void(l = r = 0);
    push(t);

    if(key <= t->key) split(t->l, key, l, t->l), r = t;
    else split(t->r, key, t->r, r), l = t;

    pull(t);
}
//junta dos sets, sin asunciones 
pnode unite(pnode l, pnode r){
    if(!l || !r) return l ? l : r;
    push(l), push(r);
    pnode t;

    if (l->prior > r->prior) swap(l, r);

    pnode rl, rr;
    split(r, l->key, rl, rr);
    l->l = unite(l->l, rl);
    l->r = unite(l->r, rr);

    pull(l);
    return l;
}

void erase(pnode &t, Key key){
    if(!t) return;
    push(t);

    if(key == t->key) t = merge(t->l, t->r);
    else if(key < t->key) erase(t->l, key);
    else erase(t->r, key);

    if(t) pull(t);
}

pnode find(pnode t, Key key){
    if(!t) return 0;

    if(key == t->key) return t;
    if(key < t->key) return find(t->l, key);

    return find(t->r, key);
}

ostream& operator<<(ostream &out, const pnode &t){
    if(!t) return out;
    return out << t->l << t->key << ' ' << t->r;
}

struct treap {
    pnode root;
    treap(pnode root = 0): root(root) {}
    int size(){ return ::size(root); }
    void insert(Key key){
        pnode t1, t2; split(root, key, t1, t2);
        t1 = ::merge(t1, new node(key));
        root = ::merge(t1,t2);
    }
    void erase(Key key1, Key key2){
        pnode t1, t2, t3;
        split(root, key1, t1, t2);
        split(t2, key2, t2, t3);
        root = merge(t1, t3);
    }
    void erase(Key key){ ::erase(root, key); }
    pnode find(Key key){ return ::find(root, key); }
    Key &operator[](int pos){ return find(pos)->key; }//ojito
};
treap merge(treap a, treap b){ return treap(merge(a.root, b.root)); }
