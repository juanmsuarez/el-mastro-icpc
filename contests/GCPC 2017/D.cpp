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

map<string, int> hm;
int h(string s) {
    if (!hm.count(s)) hm[s] = si(hm);
    return hm[s];
}

const int N = 200+10;
vi adj[N];
bool vis[N];

bool sub_path(int u, int d) {
    vis[u] = true;
    if (u == d) return true;

    for (int v : adj[u])
        if (!vis[v] && sub_path(v, d))
            return true;

    return false;
}

bool path(int u, int d) {
    fill(vis, vis+N, false);
    return sub_path(u, d);
}

int main() {
	fastio;
	
    int n, m; cin >> n >> m;
    while (n--) {
        string a, b, _;
        cin >> a >> _  >> _ >> _ >> b;
        int u = h(a), v = h(b);

        adj[u].pb(v);
    }

    while (m--) {
        string a, b, _;
        cin >> a >> _ >> _ >> _ >> b;
        int u = h(a), v = h(b);

        if (path(u, v)) cout << "Fact" << endl;
        else if (path(v, u)) cout << "Alternative Fact" << endl;
        else cout << "Pants on Fire" << endl;
    }
	
	return 0;
}
