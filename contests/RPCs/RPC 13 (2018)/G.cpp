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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N = 1e6+10;

#define rBOUND(x) (x<n? r[x] : 0)
//sa will hold the suffixes in order.
int sa[N], r[N], n;
string s; //input string, n=si(s)

int f[N], tmpsa[N];
void countingSort(int k){
    fill(f, f+N, 0);
	forn(i, n) f[rBOUND(i+k)]++;
	int sum=0;
	forn(i, max(255, n)){
		int t=f[i]; f[i]=sum; sum+=t;}
	forn(i, n)
		tmpsa[f[rBOUND(sa[i]+k)]++]=sa[i];
	memcpy(sa, tmpsa, sizeof(sa));
}
void constructsa(){//O(n log n)
	n=si(s);
	forn(i, n) sa[i]=i, r[i]=s[i];
	for(int k=1; k<n; k<<=1){
		countingSort(k), countingSort(0);
		int rank, tmpr[N];
		tmpr[sa[0]]=rank=0;
		forsn(i, 1, n)
			tmpr[sa[i]]=(r[sa[i]]==r[sa[i-1]] && r[sa[i]+k]==r[sa[i-1]+k] )? rank : ++rank;
		memcpy(r, tmpr, sizeof(r));
		if(r[sa[n-1]]==n-1) break;
	}
}
void print(){//for debug
	forn(i,n){
		cout << i << ' ';
		cout << s.substr(sa[i], s.find( '$', sa[i])-sa[i]) << endl;
    }
}

// Dado un arreglo y una operacion asociativa con neutro:
// get(i, j) opera sobre el rango [i, j).
typedef int node; // Tipo de los elementos del arreglo
typedef int alt;  // Tipo de la alteracion
#define operacion(x, y) (x + y)
const node neutro = 0; const alt neutro_alt = 0;
struct RMQ {
	int sz;
	node t[4*N];
	alt dirty[4*N];
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
			t[n] = dirty[n]*(b - a); // Altera el nodo 
			if(n < sz){
				dirty[2*n] = dirty[n];
				dirty[2*n + 1] = dirty[n];
			}
			dirty[n] = neutro_alt;
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
			dirty[n] = val;
			push(n, a, b);
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
	
    int k, m;
    cin >> m >> k >> s;     
    s += s; s += '$';

    constructsa();
    rmq.init(n);

    int last;
    forn(i, n) {
        int ind = sa[i];
        if (ind >= m) continue;

        rmq.alterar(1, ind, min(m, ind+k));
        rmq.alterar(1, 0, max(0, ind+k-m));

        last = ind;

        if (rmq.get(0, n) == m) break;
    }

    cout << s.substr(last, k) << endl;
	
	return 0;
}
