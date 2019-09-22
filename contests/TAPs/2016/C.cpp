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

const int N = 5e4;
vi adj[N];
int in_degree[N];
bool passed[N];

int registered(int u) {
    if (in_degree[u] != 0 || !passed[u]) return 0;
    
    int sum = 1;
    for (int next : adj[u]) {
        in_degree[next]--;
        sum += registered(next);
    } 

    return sum;
}

int main() {
	fastio;
	
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v; u--, v--; 
        adj[u].pb(v);
        in_degree[v]++;
    }
    vi passed_order(n); for (int &x : passed_order) {cin >> x; x--; }

    int total_registered = 0;
    for (int exam : passed_order) {
        passed[exam] = true;
        total_registered += registered(exam);
        cout << total_registered << endl;
    }
	
	return 0;
}
