//We have a vertex representing a var and other for his negation.
//Every edge stored in G represents an implication. To add an equation of the form a||b, use addor(a, b)
//N=max cant var, n=cant var
struct SAT {
    const static int N = 1e5;

    vector<int> adj[N*2];
    //idx[i]=index assigned in the dfs
    //lw[i]=lowest index(closer from the root) reachable from i
    int lw[N*2], idx[N*2], qidx;
    stack<int> q;
    int qcmp, cmp[N*2];
    //value[cmp[i]]=valor de la variable i
    bool value[N*2+1];
    int n;

    //remember to CALL INIT!!!
    void init(int _n) {
        n = _n; 
        forn(u, 2*n) adj[u].clear();
    }

    int neg(int x) { return x >=n ? x-n : x+n; }
    void addor(int a, int b) { adj[neg(a)].pb(b), adj[neg(b)].pb(a); }

    void tjn(int v){
        lw[v]=idx[v]=++qidx;
        q.push(v), cmp[v]=-2;
        for (auto u : adj[v]){
            if (!idx[u] || cmp[u]==-2){
                if (!idx[u]) tjn(u);
                lw[v]=min(lw[v], lw[u]);
            }
        }
        if (lw[v]==idx[v]){
            int x;
            do { x=q.top(); q.pop(); cmp[x]=qcmp; } while (x!=v);
            value[qcmp]=(cmp[neg(v)]<0);
            qcmp++;
        }
    }

    bool satisf(){ //O(n)
        memset(idx, 0, sizeof(idx)), qidx=0;
        memset(cmp, -1, sizeof(cmp)), qcmp=0;
        forn(i, n){
            if (!idx[i]) tjn(i);
            if (!idx[neg(i)]) tjn(neg(i));
        }
        forn(i, n) if (cmp[i]==cmp[neg(i)]) return false;
        return true;
    }
};
