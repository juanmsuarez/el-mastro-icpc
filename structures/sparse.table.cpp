#define lg(n) (31 - __builtin_clz(n))
template<class T>
struct RMQ {
    int n; vector<vector<T>> t;
    RMQ(int sz) { 
        n = sz, t.assign(lg(n)+1, vector<T>(n)); 
    }
    T& operator[](int p) { return t[0][p]; }
    T get(int i, int j) { // O(1), [i, j)
        int p = lg(j-i);
        return max(t[p][i], t[p][j - (1 << p)]);
    }
    void build() { // O(n lg n)
        forn(p, lg(n)) forn(x, n - (1 << p))
            t[p + 1][x] = max(t[p][x], t[p][x + (1 << p)]);
    }
};
