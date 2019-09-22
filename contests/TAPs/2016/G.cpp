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
using vii = vector<pii>;

const int N = 1e5, INF = 1e9;
const int K = 30;

vii adj[N];

struct Trie {
    map<bool, Trie*> children;

    void insert(int val) {
        Trie *cur = this;

        dforn(k, K) {
            int bit = val & (1<<k);
            if (!cur->children.count(bit))
                cur->children[bit] = new Trie();
            cur = cur->children[bit];
        }
    }

    int get(int val) {
        int ans = 0;
        Trie *cur = this;

        dforn(k, K) {
            bool bit = val & (1<<k);
            if (cur->children.count(!bit)) {
                ans += 1<<k;
                cur = cur->children[!bit];
            }
            else
                cur = cur->children[bit];
        }

        return ans;
    }
} trie;

void build(int u = 0, int p = -1, int path = 0) {
    trie.insert(path);

    for (auto [v, c] : adj[u]) if (v != p) 
        build(v, u, path ^ c);
}

int ans[N];
void calc(int u = 0, int p = -1, int path = 0) {
    ans[u] = trie.get(path);

    for (auto [v, c] : adj[u]) if (v != p)
        calc(v, u, path ^ c);
}

int main() {
	fastio;
	
    int n; cin >> n;
    forn(_, n - 1) {
        int u, v, c; cin >> u >> v >> c; u--, v--;
        adj[u].pb(v, c), adj[v].pb(u, c);
    } 
	
    build();
    calc();

    forn(u, n) cout << ans[u] << endl;

	return 0;
}
