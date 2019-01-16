// Usa RMQ Dynamic
// ATENCION: valores en nodos. Ver comments para valores en arcos.
template <int V, class T>
class HeavyLight {
    int parent[V], heavy[V], depth[V];
    int root[V], treePos[V];
    RMQ<V, T, T> tree;

    template <class G>
        int dfs(const G& graph, int v) {
            int size = 1, maxSubtree = 0;
            for (int u : graph[v]) if (u != parent[v]) {
                parent[u] = v;
                depth[u] = depth[v] + 1;
                int subtree = dfs(graph, u);
                if (subtree > maxSubtree) heavy[v] = u, maxSubtree = subtree;
                size += subtree;
            }
            return size;
        }

    template <class BinaryOperation>
        void processPath(int u, int v, BinaryOperation op) {
            for (; root[u] != root[v]; v = parent[root[v]]) {
                if (depth[root[u]] > depth[root[v]]) swap(u, v);
                op(treePos[root[v]], treePos[v] + 1);
            }
            if (depth[u] > depth[v]) swap(u, v);
            // ATENCION: para valores almacenados en arcos: cambiar por op(treePos[u]+1, treePos[v]+1)
            op(treePos[u], treePos[v] + 1); 
        }

    public:
    // ATENCION: grafo como vector<vector<int>>
    template <class G>
        void init(const G& graph) { 
            int n = si(graph);
            fill_n(heavy, n, -1);
            parent[0] = -1;
            depth[0] = 0;
            dfs(graph, 0);
            for (int i = 0, currentPos = 0; i < n; ++i)
                if (parent[i] == -1 || heavy[parent[i]] != i)
                    for (int j = i; j != -1; j = heavy[j]) {
                        root[j] = i;
                        treePos[j] = currentPos++;
                    }
            tree.init(n);
        }

    void set(int v, const T& value) {
        tree.modify(treePos[v], treePos[v]+1, value);
    }

    void modifyPath(int u, int v, const T& value) {
        processPath(u, v, [this, &value](int l, int r) { tree.modify(value, l, r); });
    }

    T queryPath(int u, int v) {
        T res = T();
        processPath(u, v, [this, &res](int l, int r) { res += tree.get(l, r); });
        return res;
    }
};
