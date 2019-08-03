#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = "  << a << endl
#else
    #define D(a)
    #define cerr false && cerr
#endif
#define forsn(i,s,n) for(int i = (int)s; i < (int)n;i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i, s, n) for (int i = (int)(n)-1; i >= int(s); i--)
#define pb emplace_back
#define si(a) int(a.size())
using vi = vector<int>;
using ll = long long int;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

const int N = 5e5;

typedef int node;
#define operacion(x, y) gcd(x, y)
const int neutro = 0;
struct RMQ {
    int sz;
    node t[4*N];
    node &operator [](int p) { return t[sz+p]; }
    void init(int n) {
        sz = 1 << (32 - __builtin_clz(n));
        forn(i, 2*sz) t[i] = neutro;
    }
    void updall() {
        dforsn(i, 0, sz) t[i] = operacion(t[2*i], t[2*i + 1]);
    }
    node get(int i, int j) { return get(i, j, 1, 0, sz); }
    node get(int i, int j, int n, int a, int b) {
        if (j <= a || i >= b) return neutro;
        if (i <= a && b <= j) return t[n];
        int c = (a + b) / 2;
        return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
    }
    void set(int p, node val) {
        for (p += sz; p > 0 && t[p] != val;) {
            t[p] = val;
            p /= 2;
            val = operacion(t[p*2], t[p*2 + 1]);
        }
    }
} rmq;

int main(){
    int n; cin >> n; rmq.init(n);
    forn(i, n) cin >> rmq[i]; rmq.updall();

    int q; cin >> q;
    while (q--) {
        int tipo; cin >> tipo;
        if (tipo == 1) {
            int l, r, x; cin >> l >> r >> x; l--;

            if (rmq.get(l, r) % x == 0) { cout << "YES" << endl; continue; }
            if (rmq.get(l, l+1) % x != 0) {
                cout << (rmq.get(l+1, r) % x == 0 ? "YES" : "NO") << endl;
                continue;
            }

            int lo = l, hi = r;
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (rmq.get(l, mid+1) % x == 0) lo = mid; 
                else hi = mid;
            }

            cout << (rmq.get(lo+2, r) % x == 0 ? "YES" : "NO") << endl;
        }
        else {
            int i, y; cin >> i >> y; i--;
            rmq.set(i, y);
        }
    }

}
