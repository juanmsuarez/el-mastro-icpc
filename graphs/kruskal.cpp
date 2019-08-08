struct Edge {
    int u, v, c;
    Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {}
    bool operator < (const Edge &o) const { return c < o.c; }
};

struct Kruskal {
    vector<Edge> edges;
    int n;

    Kruskal(int _n) : n(_n) {}
    void addEdge(int u, int v, int c) { edges.pb(u, v, c); }

    ll build() {
        sort(all(edges));

        UF uf(n);
        ll cost = 0;
        for (Edge &edge : edges) {
            if (uf.join(edge.u, edge.v)) {
                cost += edge.c;
            }
        }
        return cost;
    }
};
