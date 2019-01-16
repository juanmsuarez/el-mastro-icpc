#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct edge {
    int u,v,l,c;
};

int main() {
    int n,m; cin >> n >> m;
    vector<edge> e(m);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].l >> e[i].c;
        --e[i].u; --e[i].v;
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(i);
    }

    vector<ll> dist(n,INF);
    dist[0] = 0;
    set<pair<ll,int>> q;
    for (int u = 0; u < n; u++) q.emplace(dist[u],u);
    while (!q.empty()) {
        ll d; int u; tie(d,u) = *q.begin();
        q.erase(q.begin());
        for (int ind : adj[u]) {
            auto &ee = e[ind];
            int v = ee.u + ee.v - u;
            auto c = d + ee.l;
            if (c < dist[v]) {
                q.erase(make_pair(dist[v],v));
                dist[v] = c;
                q.emplace(dist[v], v);
            }
        }
    }

    vector<int> best(n,sqrt(INF));
    for (int u = 0; u < n; u++) 
        for (auto ind : adj[u]) {
            auto &ee = e[ind];
            int v = ee.u + ee.v - u;
            if (dist[u] + ee.l == dist[v]) best[v] = min(best[v], ee.c);
        }
    ll ans = 0;
    for (int u = 1; u < n; u++) ans += best[u];
    cout << ans << endl;
    return 0;
}
