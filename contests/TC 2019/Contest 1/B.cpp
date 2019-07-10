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

const int N = 1024000, INF = 1e9;

struct TipoAlt {
    int op, sz;

    TipoAlt(int _op=0, int _sz=0) : op(_op), sz(_sz) {} // 0 = todos bar, 1 = todos buc, -1 = swapear

    static TipoAlt neutro() { return ' '; } // neutro alteracion
    TipoAlt operator * (const int _sz) {
        return TipoAlt(op, _sz);
    }
    TipoAlt& operator += (const TipoAlt &o) { // propaga alteracion, ejemplo suma
        if (op == -2) op = o.op;
        else if (o.op == 0 || o.op == 1) op = o.op;
        else if (op != -1) op = 1 - op;
        return *this; 
    } 
};

struct TipoNodo {
    int bar, buc;

    TipoNodo(int _bar=0, int _buc=0) : bar(_bar), buc(_buc) {}

    static TipoNodo neutro() { return {0, 0}; } // neutro nodo
    TipoNodo operator + (const TipoNodo &o) const { return {bar + o.bar, buc + o.buc}; } // operacion nodo, ejemplo min
    TipoNodo& operator += (const TipoAlt &o) { // aplica alteracion, ejemplo suma
        if (o.op == 0) bar = o.sz, buc = 0;
        else if (o.op == 1) buc = o.sz, bar = 0;
        else swap(bar, buc);
        return *this; 
    } 
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
            dirty[i] = TAlt::neutro();
        }
    }
    void updall(){//O(n)
        dforn(i,sz) t[i] = t[2*i] + t[2*i + 1];
    }
	void push(int n, int a, int b){ // Propaga el dirty a sus hijos
		if (dirty[n].op != TAlt::neutro().op){
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
		return get(i, j, 2*n, a, c) + get(i, j, 2*n + 1, c, b);
	}
	TNodo get(int i, int j){ return get(i, j, 1, 0, sz); }
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

RMQ<N, TipoNodo, TipoAlt> rmq;

int main() {
	fastio;

    int t; cin >> t;
    forn(indt, t) {
        vi v;
        int m; cin >> m;
        while (m--) {
            int r; string s; cin >> r >> s;
            while (r--) for (char c : s) v.pb(c-'0');
        }

        int n = si(v);
        rmq.init(n);
        forn(i, n) rmq[i] = {v[i] == 0, v[i] == 1};
        rmq.updall();

        cout << "Case " << indt+1 << ":" << endl;
        int q, indq = 0; cin >> q;
        while (q--) {
            char c; int l, r; cin >> c >> l >> r; r++;
            if (c == 'S') {
                cout << "Q" << indq+1 << ": " << rmq.get(l, r).buc << endl;
                indq++;
            }
            else rmq.modify(c == 'I' ? -1 : c == 'F' ? 1 : 0, l, r);
        }
    }
	
	return 0;
}
