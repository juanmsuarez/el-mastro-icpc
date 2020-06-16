int n;
vector<vi> adj;
vector<vector<ll>> capacity;

int bfs(int s, int t, vi &parent) {
    fill(all(parent), -1);
    parent[s] = -2;
    queue<pii> q;
    q.push({s, INF});

    while (!q.empty()) {
        int u, flow; 
        tie(u, flow) = q.front(), q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vi parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}
