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
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

// Dado un arreglo y una operacion asociativa con neutro:
// get(i, j) opera sobre el rango [i, j).
typedef int node; // Tipo de los elementos del arreglo
typedef int alt;  // Tipo de la alteracion
#define operacion(x, y) max(x,y)
const node neutro = 0; const alt neutro_alt = 0;
#define MAXN 100000+10
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
	void push(int n, int a, int b){ // Propaga el dirty a sus hijos
		if(dirty[n] != neutro_alt){
			t[n] = max(dirty[n],t[n]); // Altera el nodo 
			if(n < sz){
				dirty[2*n] = max(dirty[2*n],dirty[n]);
				dirty[2*n + 1] = max(dirty[2*n+1],dirty[n]);
			}
			dirty[n] = 0;
		}
	}
	node get(int i, int j, int n, int a, int b){ // O(lg n)
		if(j <= a || i >= b) return neutro;
		push(n, a, b); // Corrige el valor antes de usarlo
		if(i <= a && b <= j) return t[n];
		int c = (a + b)/2;
		return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n + 1, c, b));
	}
	node get(int i, int j){ return get(i, j, 1, 0, sz); }
	// Altera los valores en [i, j) con una alteracion de val
	void alterar(alt val, int i, int j, int n, int a, int b){ // O(lg n)
		push(n, a, b);
		if(j <= a || i >= b) return;
		if(i <= a && b <= j){
			dirty[n] = max(val,dirty[n]);
			push(n, a, b);
			return;
		}
		int c = (a + b)/2;
		alterar(val, i, j, 2*n, a, c); alterar(val, i, j, 2*n + 1, c, b);
		t[n] = operacion(t[2*n], t[2*n + 1]);
	}
	void alterar(alt val, int i, int j){ alterar(val, i, j, 1, 0, sz); }
} rmq;

const int N =1e5+10;
int casos[55];
int seq[N];

int main() {
    fastio;

    int t;
    cin >> t;
    forn(i,t){
        cin >> casos[i];
    }
    forn(j,t){
        int n = casos[j];
        forn(i,n){
            int u,v;
            cin >> u >> v;
            u--;v--;
            seq[u]=v;
        }
        rmq.init(n);

        forn(i,n){
            int v = seq[i];
            int prev = rmq.get(0,v+1);
            //cerr << i << ' ' << v << ' ' << prev << ' ' << prev+1 << endl;
            rmq.alterar(prev+1,v,n);
        }
        cout << n-rmq.get(0,n) << endl;
    }

    return 0;
}
