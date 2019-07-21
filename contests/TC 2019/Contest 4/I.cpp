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

const int N = 1e5+2;
int n, dif[N];
vi adj[N];
bool vis[N];

int sum(int u) {
    vis[u] = true;
    int res = dif[u];

    for (int v : adj[u]) if (!vis[v]) res = (res + sum(v)) % 26;

    return res;
}

int main() {
	fastio;
	
    // leo string
    string s; cin >> s; 
    n = si(s); 
    s = 'a' + s + 'a';

    // calculo diferencias
    forn(i, n+1) dif[i] = (s[i+1] - s[i] + 26) % 26;

    // agrego arcos
    int k; cin >> k;
    while (k--) {
        int l, r; cin >> l >> r; l--;
        adj[l].pb(r), adj[r].pb(l);
    }
    forn(i, (n+1)/2) {
        int j = n-i;
        adj[i].pb(j), adj[j].pb(i);
    }

    // controlo suma
    bool can = true;
    forn(u, n+1) if (!vis[u] && sum(u) != 0) can = false;

    cout << (can ? "YES" : "NO") << endl;
	
	return 0;
}
