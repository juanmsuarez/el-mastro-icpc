struct Edge {
    int u, v, c;
    bool operator<(const Edge &o) const { return c < o.c; }
};
struct Kruskal {
    vector<Edge> edges;
    void addEdge(int u, int v, int c) { 
        edges.pb(Edge{u, v, c}); 
    }
    ll build(int n) {
        sort(all(edges));
        ll cost = 0;
        UF uf(n);
        for (Edge &e : edges)
            if (uf.join(e.u, e.v)) cost += e.c;
        return cost;
    }
};
