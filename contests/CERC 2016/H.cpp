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
typedef vector<pii> vii;

struct UnionFind{
	vector<int> f; // Arreglo que contiene los padres de cada nodo
	void init(int n){ f.clear(); f.insert(f.begin(), n, -1); }
	int comp(int x){ return f[x] == -1 ? x : f[x] = comp(f[x]); } // O(1)
	bool join(int i, int j){
		bool con = comp(i) == comp(j);
		if(!con) f[comp(i)] = comp(j);
		return con;
	}
} uf;

typedef tuple<int,int,int,int> query;

const int N = 1e3+10, M = 3e5+10;
const int di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, 1, -1};
bool ocu[N][N];
int n, acum[N][N], ans[M], sz[N][N];
vii vsz[N];
query qs[M];

int get(int a, int b, int c, int d) {
    return acum[c+1][d+1] - acum[a][d+1] - acum[c+1][b] + acum[a][b];
}

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

bool can(int i, int j, int r) {
    if (!valid(i-r, j-r) || !valid(i+r, j+r)) return false;
    return get(i-r, j-r, i+r, j+r) == 0;
}

int main() {
	fastio;
	
    cin >> n;
    forn(i, n) forn(j, n) {
        char c; cin >> c;
        ocu[i][j] = c == '#';
        acum[i+1][j+1] = acum[i+1][j] + acum[i][j+1] - acum[i][j] + ocu[i][j]; 
    }    
    int q; cin >> q;
    forn(i, q) {
        int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2; 
        i1--, j1--, i2--, j2--;
        qs[i] = {i1, j1, i2, j2};
    }

    forn(i, n) forn(j, n) {
        if (ocu[i][j]) {
            sz[i][j] = -1;
            continue;
        } 

        int lo = 0, hi = n;
        while (hi - lo > 1) {
            int mid = (lo+hi)/2;
            if (can(i, j, mid)) lo = mid;
            else hi = mid;
        }
        sz[i][j] = lo;
        vsz[lo].pb(i, j);
    }

    uf.init(n*n);
    fill(ans, ans+q, -1);
    dforn(r, n) {
        for (pii c : vsz[r]) {
            int i, j; tie(i, j) = c;

            forn(d, 4) {
                int ni = i + di[d], nj = j + dj[d];

                if (valid(ni, nj) && sz[ni][nj] >= r) {
                    int a = i*n+j, b = ni*n+nj;
                    uf.join(a, b);
                }
            }
        }

        forn(i, q) {
            if (ans[i] != -1) continue;            

            int i1, j1, i2, j2; tie(i1, j1, i2, j2) = qs[i];
            int a = i1*n+j1, b = i2*n+j2;
            if (uf.comp(a) == uf.comp(b)) ans[i] = r;
        }
    }

    forn(i, q) cout << (ans[i] == -1 ? 0 : 2*ans[i]+1) << endl;
	
	return 0;
}
