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
using vb = vector<bool>;

int main() {
	fastio;
	
    int n, d; cin >> n >> d;
    vb val; forn(u, n) { int v; cin >> v; val.pb(v); }
    vi par(n);
    forn(u, n) {
        cin >> par[u];
        if (par[u] != -1) par[u]--;
    }

    vb best_path;
    forn(u, n) {
        vb path;

        int cur = u;
        forn(_, d) {
            path.pb(val[cur]);
            cur = par[cur];
            if (cur == -1) break;
        }
        if (si(path) != d) continue;
        reverse(all(path));

        if (path > best_path) best_path = path;
    }

    forn(i, d) cout << best_path[i] << " \n"[i == d - 1];
	
	return 0;
}
