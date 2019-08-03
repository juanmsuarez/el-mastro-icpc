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
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
#define fst first
#define snd second
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN = 2e5+10, INF = 1e9+1;

// Dado un arreglo y una operacion asociativa con neutro:
// get(i, j) opera sobre el rango [i, j).
typedef int node; // Tipo de los nodos
#define operacion(x, y) min(x, y)
const int neutro = INF;
const pii pneutro = {INF, INF};
struct RMQ {
	int sz;
	node t[4*MAXN];
	node &operator [](int p){ return t[sz + p]; }
	void init(int n){ // O(n lg n)
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro;
	}

	pii get(int mx){ return get(1, 0, sz, mx); }

	pii get(int n, int a, int b, int mx){ // O(lg n)
		if (t[n] > mx) return pneutro;
        if (a+1 == b) return {t[n], n-sz};

		int c = (a + b)/2;
        pii p = get(2*n, a, c, mx);
        if (p != pneutro)
            return p;
        else
            return get(2*n+1, c, b, mx);
	}

	void set(int p, node val){ // O(lg n)
		for(p += sz; p > 0 && t[p] != val;){
			t[p] = val;
			p /= 2;
			val = operacion(t[p*2], t[p*2 + 1]);
		}
	}
} rmq;

int sol[MAXN];

int main() {
    fastio;

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
   
    int h, w, n;
    cin >> h >> w >> n;
    rmq.init(n);
    fill(sol, sol+n, -1);
    forn(i, n) {
        int a;
        cin >> a;
        rmq.set(i, a);
    } 

    int i = 0, j = 0;
    while (i < h) {
        bool found = rmq.get(w-j) != pneutro;
        if (!found) break;

        while (j < w && found) {
            found = false;
            
            pii p = rmq.get(w-j);
            if (p != pneutro) {
                found = true;
                sol[p.snd] = i+1;
                rmq.set(p.snd, INF);
                j += p.fst;
            }
        }
        i++;
        j = 0;
    } 

    forn(k, n) cout << sol[k] << endl;

    return 0;
}
