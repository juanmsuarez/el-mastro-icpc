#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

struct TipoAlt {
    int val;

    TipoAlt(int _val=0) : val(_val) {}

    static TipoAlt neutro() { return 0; } // neutro alteracion
    TipoAlt operator * (const int sz) { return TipoAlt(val); }
    TipoAlt& operator += (const TipoAlt &o) { val += o.val; return *this; } // propaga alteracion, ejemplo suma
};

struct TipoNodo {
    int val;
    int ind;

    TipoNodo(int _val = 0, int _ind = 0) : val(_val), ind(_ind) {}

    static TipoNodo neutro() { return {0, -1}; } // neutro nodo
    TipoNodo operator + (const TipoNodo &o) const { return val > o.val ? *this : o; } // operacion nodo
    TipoNodo& operator += (const TipoAlt &o) { val += o.val; return *this; } // aplica alteracion
};

// Dado un arreglo y una operacion asociativa con neutro:
// get(i, j) opera sobre el rango [i, j).
template <int N, class TNodo, class TAlt>
struct RMQ {
	int sz;
	TNodo t[4*N];
	TAlt dirty[4*N];
	TNodo &operator [](int p){ return t[sz + p]; }
    void init(int n) { // O(n lg n)
        sz = 1 << (32 - __builtin_clz(n));
        forn(i, 2*sz) {
            t[i] = TNodo::neutro();
            if (i >= sz) t[i].ind = i - sz;
            dirty[i] = TAlt::neutro();
        }
    }
    void upd_all() {
        dforsn(i, 0, sz) t[i] = t[2 * i] + t[2 * i + 1];
    }
	void push(int n, int a, int b){ // Propaga el dirty a sus hijos
		if (dirty[n].val != TAlt::neutro().val){
			t[n] += dirty[n]*(b-a); // Altera el nodo 
			if (n < sz){
				dirty[2*n] += dirty[n];
				dirty[2*n + 1] += dirty[n];
			}
			dirty[n] = TAlt::neutro();
		}
	}
	TNodo get(int i, int j, int n, int a, int b){ // O(lg n)
		if (j <= a || i >= b) return TNodo::neutro();
		push(n, a, b); // Corrige el valor antes de usarlo
		if (i <= a && b <= j) return t[n];
		int c = (a + b)/2;
		TNodo temp =  get(i, j, 2*n, a, c) + get(i, j, 2*n + 1, c, b);
        cerr << "max en " << a << ' ' << b << " = " << temp.val << endl;
        return temp;
	}
	TNodo get(int i, int j) { return get(i, j, 1, 0, sz); }
	// Altera los valores en [i, j) con una alteracion de val
	void modify(TAlt val, int i, int j, int n, int a, int b){ // O(lg n)
		push(n, a, b);
		if (j <= a || i >= b) return;
		if (i <= a && b <= j) {
			dirty[n] += val;
			push(n, a, b);
			return;
		}
		int c = (a + b)/2;
		modify(val, i, j, 2*n, a, c); modify(val, i, j, 2*n + 1, c, b);
		t[n] = t[2*n] + t[2*n + 1];
	}
	void modify(TAlt val, int i, int j){ modify(val, i, j, 1, 0, sz); }
};

const int N = 1e5;

int par[N];
vi children[N];

RMQ<N, TipoNodo, TipoAlt> depth;
int euler_time = 0, euler[N], euler_left[N], euler_right[N];

void build_euler(int u = 0, int d = 1) {
    euler_left[u] = euler_time;
    euler[euler_time] = u;
    depth[euler_time++].val = d;

    for (int v : children[u]) build_euler(v, d + 1);

    euler_right[u] = euler_time; 
}

bool painted[N];

int main() {
	fastio;

    par[0] = -1;

    int n, k; cin >> n >> k;
    forsn(u, 1, n) {
        int p; cin >> p; p--;
        children[p].pb(u);
        par[u] = p;
    }

    //cerr << "euler" << endl;

    depth.init(n);
    build_euler(); 
    depth.upd_all();

    //cerr << "work" << endl;

    int painted_count = 0;
    while (k > 0 && painted_count < n) {
        int pos_best = depth.get(0, n).ind;
        int u = euler[pos_best];
        cerr << "best " << u << endl;

        while (u != -1 && !painted[u]) {
            depth.modify(-1, euler_left[u], euler_right[u]);

            painted[u] = true;
            painted_count++;

            u = par[u];
        }

        k--;
    }

    cout << painted_count << endl;

	return 0;
}
