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
typedef long long int ll;

const int MAXN = 3e5+10; 
vector<ll> points;

// Dado un arreglo y una operacion asociativa con neutro:
// get(i, j) opera sobre el rango [i, j).
typedef bool node; // Tipo de los elementos del arreglo
typedef int alt;  // Tipo de la alteracion
const node neutro = true; const alt neutro_alt = -1;
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
            if (n >= sz)
                t[n] = dirty[n]; // Altera el nodo 
			if(n < sz){
				dirty[2*n] = dirty[n];
				dirty[2*n + 1] = dirty[n];
			}
			dirty[n] = neutro_alt;
		}
	}
	node get(int pos, int n, int a, int b){ // O(lg n)
		if (pos < a || pos >= b) return neutro;
		push(n); // Corrige el valor antes de usarlo
        if (a+1 == b) {
            //cerr << " query " << points[a] << ' ' << points[b-1] << ' ' << t[n] << endl;
            return t[n];
        }
		int c = (a + b)/2;
        if (pos < c)
            return get(pos, 2*n, a, c);
        else
            return get(pos, 2*n+1, c, b);
	}
	node get(int pos){ return get(pos, 1, 0, sz); }
	// Altera los valores en [i, j) con una alteracion de val
	void alterar(alt val, int i, int j, int n, int a, int b){ // O(lg n)
		push(n);
		if(j <= a || i >= b) return;
		if(i <= a && b <= j){
			dirty[n] = val;
			push(n);
            //cerr << "altero " << points[a] << ' ' << points[b] << ' ' << t[n] << endl;
			return;
		}
		int c = (a + b)/2;
		alterar(val, i, j, 2*n, a, c); alterar(val, i, j, 2*n + 1, c, b);
	}
	void alterar(alt val, int i, int j){ alterar(val, i, j, 1, 0, sz); }
} rmq;

bool allow[MAXN];
ll lo[MAXN], hi[MAXN];
ll q[MAXN];
map<ll, int> h;

int main() {
    fastio;

    freopen("access.in", "r", stdin);
    freopen("access.out", "w", stdout);


    int n, m;
    string _;
    cin >> n;
    getline(cin, _);

    forn(i, n) {
        string line, s;
        getline(cin, line);
        istringstream in(line);
        in >> s >> _;
        allow[i] = s == "allow";
        //cerr << i << ' ' << s << endl;

        char ch; ll a, b, c, d, e;
        in >> a >> ch >> b >> ch >> c >> ch >> d;
        //cerr << a << ' ' << b << ' '<< c << ' '<< d << ' ' << endl;
        lo[i] = (((a*256+b)*256+c)*256+d);
        if (!in.eof()) {
            in >> ch;
            in >> e;

            hi[i] = lo[i]+(1LL<<(32-e));
        }
        else hi[i] = lo[i]+1;

        points.pb(lo[i]);
        points.pb(hi[i]);
        //cerr << lo[i] << ' '<< hi[i] << endl;
    }    

    cin >> m;
    getline(cin,_);
    forn(i, m) {
        string line, s;
        getline(cin, line);
        istringstream in(line);
        char ch; ll a, b, c, d;
        in >> a >> ch >> b >> ch >> c >> ch >> d;
        q[i] = (((a*256+b)*256+c)*256+d);
        points.pb(q[i]); 
    }

    sort(all(points));
    points.erase(unique(all(points)), points.end());
    int k = si(points);
    forn(i, k) h[points[i]] = i;

    rmq.init(k);
    dforsn(i, 0, n) 
        rmq.alterar(allow[i], h[lo[i]], h[hi[i]]);

    forn(i, m) {
        //cerr << "pide " << q[i] << ' '  << h[q[i]] << endl;
        cout<< (rmq.get(h[q[i]]) ? 'A' : 'D') ;
    }

    return 0;
}
