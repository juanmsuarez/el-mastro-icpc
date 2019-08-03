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

typedef int tipo;
tipo mcd(tipo a, tipo b){return a?mcd(b%a, a):b;}
struct frac{
	tipo p,q;
	frac(tipo p=0, tipo q=1):p(p),q(q) {norm();}
	void norm(){
		tipo a = mcd(p,q);
		if(a) p/=a, q/=a;
		else q=1;
		if (q<0) q=-q, p=-p;}
	frac operator+(const frac& o){
		tipo a = mcd(q,o.q);
		return frac(p*(o.q/a)+o.p*(q/a), q*(o.q/a));}
	frac operator-(const frac& o){
		tipo a = mcd(q,o.q);
		return frac(p*(o.q/a)-o.p*(q/a), q*(o.q/a));}
	frac operator*(frac o){
		tipo a = mcd(q,o.p), b = mcd(o.q,p);
		return frac((p/b)*(o.p/a), (q/a)*(o.q/b));}
	frac operator/(frac o){
		tipo a = mcd(q,o.q), b = mcd(o.p,p);
		return frac((p/b)*(o.q/a),(q/a)*(o.p/b));}
	bool operator<(const frac &o) const{return p*o.q < o.p*q;}
	bool operator==(frac o){return p==o.p&&q==o.q;}
};

const frac unmedio = {1, 2};

vector<pii> adj;
void addEdge(int u, int v) {
    if (si(adj) <= u) {
        adj.resize(u+1);
        adj[u].first = v;
    }
    else
        adj[u].second = v;
}

int main() {
    fastio;

    freopen("drunkard.in", "r", stdin); freopen("drunkard.out", "w", stdout);
    
    int p, q;
    while (cin >> p >> q && p != 0) {
        adj.clear();

        frac f(p,q);

        map<frac, int> visto;

        int act = 0;
        while (f.p != 0 && visto[f] == 0) {
            if (act > 0) addEdge(act, act+1); 

            act++;

            visto[f] = act;

            if (!(f < unmedio)) {
                f = f - unmedio;
                addEdge(act, -2);
            }
            else 
                addEdge(act, -1);

            f.p *= 2;
            f.norm();
        }

        if (f.p != 0)
            addEdge(act, visto[f]);
        else 
            addEdge(act, -1);

        int n = act + 2;
        cout << n << endl;
        forsn(i, 1, act+1) {
            int u = adj[i].first, v = adj[i].second;
            if (u == -1) u = n; else if (u == -2) u = n-1;
            if (v == -1) v = n; else if (v == -2) v = n-1;
            cout << u << ' ' << v << endl;
        }
    }

    return 0;
}
