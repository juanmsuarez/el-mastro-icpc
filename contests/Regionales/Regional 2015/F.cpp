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
#define DBG(a) //cerr << #a << "=" << a << endl
#else
#define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

struct pto {
    int x, y, val;
    pto(int x = 0, int y = 0, int val = 0) : x(x), y(y), val(val) {}
    bool operator < (const pto &o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

// Dado un arreglo y una operacion asociativa con neutro:
// get(i, j) opera sobre el rango [i, j).
typedef bool node; // Tipo de los elementos del arreglo
typedef int alt;  // Tipo de la alteracion
#define operacion(x, y) (x || y)
const node neutro = false; const alt neutro_alt = -1;
#define MAXN 200010
struct RMQ {
    int sz;
    node t[4*MAXN];
    alt dirty[4*MAXN];
    node &operator [](int p){ return t[sz + p]; }
    void init(int n){ // O(n lg n)
        sz = 1 << (32 - __builtin_clz(n));
        forn(i, 2*sz){
            t[i] = neutro;
            dirty[i] = neutro_alt;
        }
    }
    void push(int n){ // Propaga el dirty a sus hijos
        if(dirty[n] != neutro_alt){
            t[n] = dirty[n]; // Altera el nodo 
            if(n < sz){
                dirty[2*n] = dirty[n];
                dirty[2*n + 1] = dirty[n];
            }
            dirty[n] = neutro_alt;
        }
    }
    node get(int i, int j, int n, int a, int b){ // O(lg n)
        if(j <= a || i >= b) return neutro;
        push(n); // Corrige el valor antes de usarlo
        if(i <= a && b <= j) return t[n];
        int c = (a + b)/2;
        return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n + 1, c, b));
    }
    node get(int i){ return get(i, i+1, 1, 0, sz); }
    // Altera los valores en [i, j) con una alteracion de val
    void alterar(alt val, int i, int j, int n, int a, int b){ // O(lg n)
        push(n);
        if(j <= a || i >= b) return;
        if(i <= a && b <= j){
            dirty[n] = val;
            push(n);
            return;
        }
        int c = (a + b)/2;
        alterar(val, i, j, 2*n, a, c); alterar(val, i, j, 2*n + 1, c, b);
        t[n] = operacion(t[2*n], t[2*n + 1]);
    }
    void alterar(alt val, int i, int j){ alterar(val, i, j, 1, 0, sz); }
} rmq;

int main() {
    fastio;

    int P, V;
    while (cin >> P >> V) {
        vector<pto> v;

        vi ys;
        map<int,int> cmp;

        forn(i, P) {
            int x, y;
            cin >> x >> y;
            v.pb(x, y, i+1);
            ys.pb(y);
        }
        forn(i, V) {
            int x, y;
            cin >> x >> y;
            v.pb(x, y, 0);
            ys.pb(y);
        }
        sort(all(ys));
        forn(i, si(ys)) cmp[ys[i]] = i;

        sort(all(v));

        ll ans = 0;

        pto pre;
        bool hasPre = false;
        rmq.init(P+V);
        for (pto p : v) {
            //cerr << "veo " << p.x << ' ' << p.y << endl;
            if (p.val == 0) {
                if (hasPre) {
                    if (rmq.get(cmp[pre.y])) { // elim
                        //cerr << "Elim" << endl;
                        rmq.alterar(false, cmp[pre.y], cmp[p.y]);
                    }
                    else  { // ins
                        //cerr << "Ins" << endl;
                        rmq.alterar(true, cmp[pre.y], cmp[p.y]);
                    }
                }
                else
                    pre = p;

                hasPre = !hasPre;
            } 
            else
                if (!rmq.get(cmp[p.y])) {
                    //cerr << "OUT " << p.x << ' ' << p.y << endl;
                    ans += p.val;
                }
        }

        //cerr << "ANS"<<endl;
        cout << ans << endl;
    }

    return 0;
}
