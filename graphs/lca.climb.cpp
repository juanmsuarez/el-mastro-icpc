const int MAXN=100001;
const int LOGN=20;
//f[v][k] holds the 2^k father of v
//L[v] holds the level of v
int N, f[MAXN][LOGN], L[MAXN]; //INICIALIZAR N!!!!!!!!!!!!!!
//call before build:
void dfs(int u, int fa=-1, int lvl=0){ // generate required data
	f[u][0]=fa, L[u]=lvl;
	for (auto v : G[u]) if (v != fa) dfs(v, u, lvl+1); 
}
void build(){ //f[i][0] must be filled previously, O(nlgn)
	forn(k, LOGN-1) forn(i, N) if (f[i][k]!=-1) f[i][k+1]=f[f[i][k]][k];
}
#define lg(x) (31-__builtin_clz(x))//=floor(log2(x))
int climb(int a, int d){//O(lgn)
	if(!d) return a;
	dforsn(i, 0, lg(L[a])+1) if(1<<i<=d) a=f[a][i], d-=1<<i;
    return a;
}
int lca(int a, int b){//O(lgn)
	if (L[a]<L[b]) swap(a, b);
	a = climb(a, L[a]-L[b]);
	if (a==b) return a;
	dforsn(i, 0, lg(L[a])+1) if (f[a][i]!=f[b][i]) a=f[a][i], b=f[b][i];
	return f[a][0]; 
}
int dist(int a, int b) {//returns distance between nodes
	return L[a]+L[b]-2*L[lca(a, b)];
}
