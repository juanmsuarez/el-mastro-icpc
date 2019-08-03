#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
    #define cerr  false && cerr
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN = 1e5+10;

// Dado un arreglo y una operacion asociativa con neutro:
// get(i, j) opera sobre el rango [i, j).
struct node {
    double pAD, pD;
    node (double pAD = 1, double pD = 0) : pAD(pAD), pD(pD) {}
};
node merge(node a, node b) {
    double npCD = b.pAD/(1-(1-b.pAD)*a.pD);
    return node(a.pAD*npCD, b.pD+(1-b.pD)*a.pD*npCD);
}
const node neutro = {1,0};
struct RMQ {
    int sz;
    node t[4*MAXN];
    node &operator [](int p){ return t[sz + p]; }
    void init(int n){ // O(n lg n)
        sz = 1 << (32 - __builtin_clz(n));
        forn(i, 2*sz) t[i] = neutro;
    }
    void updall(){//O(n)
        dforsn(i,0, sz){
            t[i] = merge(t[2*i], t[2*i + 1]);
        }
    }
    node get(int i, int j){ return get(i, j, 1, 0, sz); }
    node get(int i, int j, int n, int a, int b){ // O(lg n)
        if(j <= a || i >= b) return neutro;
        if(i <= a && b <= j) return t[n];
        int c = (a + b)/2;
        return merge(get(i, j, 2*n, a, c), get(i, j, 2*n + 1, c, b));
    }
    void set(int p, node &val){ // O(lg n)
        for(p += sz; p > 0;){
            t[p] = val;
            p /= 2;
            val = merge(t[p*2], t[p*2 + 1]);
        }
    }
    /*
    void print() { print(0,sz,1); }
    void print(int l, int r, int ind) {
        cerr << l << ' ' << r << ' ' << t[ind].pAD << ' ' << t[ind].pD << endl;
        int mid = (l+r)/2;
        if (l+1 == r || l == r) return;
        print(l, mid, 2*ind); print(mid, r, 2*ind+1);
    }
    */
} rmq;

int main() {
    fastio;

    int n, q; cin >> n >> q;
    rmq.init(n);
    forn(i, n) {
        int a, b; cin >> a >> b;
        double p = (double)a/b; node e(p, p);
        rmq[i] = e;
    }
    rmq.updall();
    //rmq.print();

    cout << fixed << setprecision(4);
    while (q--) {
        int tipo; cin >> tipo;
        if (tipo == 1) {
            int i, a, b; cin >> i >> a >> b; i--;
            double p = (double)a/b; node e(p, p);
            rmq.set(i, e);
        }        
        else {
            int l, r; cin >> l >> r; l--;
            cout << rmq.get(l, r).pAD << endl;
        }
    }

    return 0;
}
