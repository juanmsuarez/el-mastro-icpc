#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forsn(i, s, n) for (int i = (int)(s); i < (int)(n); i++) 
#define all(a) a.begin(),a.end()
#define si(a) ((int)(a).size())
#define pb emplace_back
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fst first
#define snd second
using vi = vector<int>;
using ll = long long;
using pii = pair<int,int>;

const int N = 1e4;
vi adj[N];

pii farthest(int u, int p = -1) {
    pii ans = {-1, u};

    for (int v : adj[u])
        if (v != p)
            ans = max(ans, farthest(v, u));

    ans.fst++;
    return ans;
}

int diam(int r = 0) {
    return farthest(farthest(r).snd).fst;
}

int main(){
    fastio;

    int n; 
    while (cin >> n && n != -1) {
        forn(u, n) adj[u].clear();
        forsn(u, 1, n) {
            int v; cin >> v; v--;
            adj[u].pb(v), adj[v].pb(u);
        }

        cout << (diam()+1)/2 << endl;
    }

    return 0;
}
