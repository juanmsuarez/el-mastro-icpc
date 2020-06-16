const int INF = 1e9;
template<class T>
struct EK {
    int n;
    vector<vi> adj;
    vector<vector<T>> capacity;
    
    EK(int _n) : n(_n) {
        adj = vector<vi>(n);
        capacity = vector<vector<T>>(n, vector<T>(n));
    }

    void addEdge(int u, int v, T c) {
        adj[u].pb(v), adj[v].pb(u); 
        capacity[u][v] = c;
    }
    
    T bfs(int s, int t, vi &parent) {
        fill(all(parent), -1);
        parent[s] = s;
        queue<pair<int, T>> q;
        q.emplace(s, INF);
        while (!q.empty()) {
            int u = q.front().fst;
            T flow = q.front().snd;
            q.pop();
            for (int v : adj[u]) {
                if (parent[v] == -1 && capacity[u][v]) {
                    parent[v] = u;
                    T new_flow = min(flow, capacity[u][v]);
                    if (v == t) return new_flow;
                    q.emplace(v, new_flow);
                }
            }
        }
        return 0;
    }
    
    T maxflow(int s, int t) {
        T flow = 0, new_flow;
        vi parent(n);
        while ((new_flow = bfs(s, t, parent))) {
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
};
