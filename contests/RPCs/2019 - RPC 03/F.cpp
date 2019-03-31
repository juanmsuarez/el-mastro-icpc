#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio //ios_base::sync_with_stdio(0); cin.tie(0)
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
//#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MAXN = 2e5+10, MAXSZ = 1e5+10;



vi cordX,cordY;
map<int,int>indX,indY;

int dist(int a,int b){
    return cordY[b]-cordY[a];
}

struct Tipo {
    const static int neutro = 0;
    int val;

    Tipo(int _val=0) : val(_val) {}

    Tipo operator + (const Tipo &o) const { return (val & o.val)%2; }
    Tipo& operator += (const Tipo &o) { val = (val^o.val); return *this; }
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
            t[i] = TNodo::neutro;
            dirty[i] = TAlt::neutro;
        }
    }
	void push(int n, int a, int b){ // Propaga el dirty a sus hijos
		if (dirty[n].val != TAlt::neutro){
			t[n] += dirty[n].val*(b - a); // Altera el nodo
			if (n < sz){
				dirty[2*n] += dirty[n];
				dirty[2*n + 1] += dirty[n];
			}
			dirty[n] = TAlt::neutro;
		}
	}
	int get(int i, int j, int n, int a, int b){ // O(lg n)
        int res;
		if (j <= a || i >= b) res = 0;
        else{
            push(n, a, b); // Corrige el valor antes de usarlo
            if (i <= a && b <= j) res = dist(a,b)*t[n].val;
            else{
                int c = (a + b)/2;
                res = get(i, j, 2*n, a, c)+ get(i, j, 2*n + 1, c, b);
            }
        }
        cerr << a << " " << b << "= " <<res << endl;
        return res;
	}
	int get(int i, int j){ return get(i, j, 1, 0, sz); }
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

RMQ<MAXSZ,Tipo,Tipo> segTree;

struct rect{
    pii p1,p2;
};


int main() {


    int n;
    cin >> n;
    D(n);

    vector<rect> rs(n);
    for(rect& r:rs){
        cin >> r.p1.fst >> r.p1.snd >> r.p2.fst >> r.p2.snd;
        cordX.pb(r.p1.fst);
        cordX.pb(r.p2.fst);
        cordY.pb(r.p1.snd);
        cordY.pb(r.p2.snd);
    }

    cerr << "start cord comp" << endl;
    sort(all(cordX));
    sort(all(cordY));
    cordX.resize(unique(all(cordX))-cordX.begin());
    cordY.resize(unique(all(cordY))-cordY.begin());

    forn(i,si(cordX))indX[cordX[i]]=i;
    forn(i,si(cordY))indY[cordY[i]]=i;

    vector<vector<pii>>open(MAXN,vector<pii>()),close(MAXN,vector<pii>());

    for(rect r:rs){
        open[indX[r.p1.fst]].pb(mp(indY[r.p1.snd],indY[r.p2.snd]));
        close[indX[r.p2.fst]].pb(mp(indY[r.p1.snd],indY[r.p2.snd]));
    }

    cerr << "start calc" << endl;

    ll res =0;

    int sz = si(cordY);
    segTree.init(sz-1);

    forn(i,si(cordX)){
        ll dx = 0;
        cerr << i << " " << cordX[i] << endl;
        if(i+1!=si(cordX))dx= cordX[i+1]-cordX[i];
        D(dx);
        forn(j,si(open[i])){
            segTree.modify({1},open[i][j].fst,open[i][j].snd);
            cerr << "op " << cordY[i] << " " << open[i][j].fst << " " << open[i][j].snd << endl;
        }
        forn(j,si(close[i])){
            segTree.modify({1},close[i][j].fst,close[i][j].snd);
            cerr << "close " << cordY[i] << " " << close[i][j].fst << " " << close[i][j].snd << endl;
        }

        res+=dx* ll(segTree.get(0,sz-1));
        D(res);


    }

    cout << res << endl;



	return 0;
}

