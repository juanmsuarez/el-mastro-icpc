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

const int N = 1e3, C = 50+1;
int a[N][N];

int main() {
	fastio;

    freopen("control.in", "r", stdin);
    freopen("control.out", "w", stdout);
	
    int n, m; cin >> n >> m;
    forn(i, n) forn(j, m) cin >> a[i][j];

    map<int, vi> adj;
    forsn(i, 1, n) {
        forn(j, n) {
            int x = a[0][j], y = a[i][j];
            if (x != y) {
                adj[x].pb(y), adj[y].pb(x);
                break;
            }
        }
    }
    
    map<int, int> color;
    for (auto &[u, vs] : adj) {
        vector<bool> used(C);
        for (int v : vs) if (color.count(v)) used[color[v]] = true;

        int c = 0; while (used[c]) c++;
        color[u] = c;
    }
    forn(i, n) forn(j, m) {
        int x = a[i][j];
        if (!color.count(x)) color[x] = 0;
    }

    cout << "Yes" << endl;
    for (auto &[u, c] : color) cout << u << " -> " << c << endl;
	
	return 0;
}
