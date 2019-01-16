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
typedef long long int tint;

const int MAXN = 1e3+10;

int arr[MAXN][MAXN], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
pii query[MAXN][2];

struct UnionFind{
	vector<int> f; // Arreglo que contiene los padres de cada nodo
	void init(int n){ f.clear(); f.insert(f.begin(), n, -1); }
	int comp(int x){ return f[x] == -1 ? x : f[x] = comp(f[x]); } // O(1)
	bool join(int i, int j){
		bool con = comp(i) == comp(j);
		if(!con) f[comp(i)] = comp(j);
		return con;
	}
};

UnionFind uf;
int n, m, q;
int cant;

int valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void paint(pii a, pii b, int val) {
    int x1 = a.first, y1 = a.second,
        x2 = b.first, y2 = b.second;

    if (x1 == x2) {
        if (y2 < y1) swap(y1, y2);
        forsn(y, y1, y2+1) {
            //cerr << "pinto " << x1 << ' ' << y << endl;
            arr[x1][y] += val;
        }
    }
    else {
        if (x2 < x1) swap(x1, x2);
        forsn(x, x1, x2+1) {
            //cerr << "pinto " << x << ' ' << y1 << endl;
            arr[x][y1] += val;
        }
    }
}

void undo1(int x, int y) {
    //cerr << "despinto " << x << ' ' << y << " queda " << arr[x][y] << endl;
    if (arr[x][y] == 0) {
        cant++;
        forn(d, 4) {
            int nx = x+dx[d], ny = y+dy[d];

            //cerr << "intento unir con " << nx << ' ' << ny << endl;
            //cerr << valid(nx,ny) << ' ' << (arr[nx][ny]==0) << endl;
            if (valid(nx, ny) && arr[nx][ny] == 0 && !uf.join(x*m+y, nx*m+ny)) {
                //cerr << "uno " << x << ' ' << y << ' ' << nx << ' ' << ny << endl;
                cant--;
            }
        }
    }
}

void undo(pii a, pii b) {
    int x1 = a.first, y1 = a.second,
        x2 = b.first, y2 = b.second;

    if (x1 == x2) {
        if (y2 < y1) swap(y1, y2);
        forsn(y, y1, y2+1) 
            undo1(x1, y);
    }
    else {
        if (x2 < x1) swap(x1, x2);
        forsn(x, x1, x2+1)
            undo1(x, y1);
    }
}


int main() {
    fastio;

    cin >> n >> m >> q; 
    forn(i, q) {
        cin >> query[i][0].first >> query[i][0].second >> query[i][1].first >> query[i][1].second;
        query[i][0].first--; query[i][0].second--;
        query[i][1].first--; query[i][1].second--;
        paint(query[i][0], query[i][1], 1);
    }

    uf.init(n*m);

    cant = 0;
    forn(x, n) forn(y, m)
        if (arr[x][y] == 0) {
            cant++;

            forn(d, 4) {
                int nx = x+dx[d], ny = y+dy[d];

                if (valid(nx, ny) && arr[nx][ny] == 0) 
                    if (!uf.join(x*m+y, nx*m+ny)) { 
                        //cerr << "uno " << x << ' ' << y << ' ' << nx << ' ' << ny << endl;
                        cant--;
                    }
            }
        }
    //cerr << "init " << cant << endl;

    vi ans;
    dforsn(i, 0, q) {
        //cerr << "CANT " << cant << endl;
        ans.pb(cant);

        paint(query[i][0], query[i][1], -1);

        undo(query[i][0], query[i][1]);
    }
    
    dforsn(i, 0, q)
        cout << ans[i] << endl;

    return 0;
}
