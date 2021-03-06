const int N = 5e4, M = 2*N;
int m;
vi adj[N]; 
vii adjb[M];

void init_binarization(int n) {
    m = n;
}

void binarize(int u = 0, int p = -1) {
    int act = u;
    for (int v : adj[u]) if (v != p) {
        adjb[act].pb(v, 1); adjb[v].pb(act, 1);
        binarize(v, u);

        int w = m++; 
        adjb[act].pb(w, 0); adjb[w].pb(act, 0);

        act = w;
    }
}
