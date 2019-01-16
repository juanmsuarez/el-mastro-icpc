#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXRC = 20+5, MAXN = 20*20+5, INF = 1e9;

int nodes, src, dst;
int dist[MAXN], q[MAXN], work[MAXN];
struct Edge {
    int to, rev;
    ll f, cap;
    Edge(int to, int rev, ll f, ll cap) : to(to), rev(rev), f(f), cap(cap) {}
};
vector<Edge> G[MAXN];
void addEdge(int s, int t, ll cap){
    G[s].pb(Edge(t, si(G[t]), 0, cap)), G[t].pb(Edge(s, si(G[s])-1, 0, 0));}
bool dinic_bfs(){
    fill(dist, dist+nodes, -1), dist[src]=0;
    int qt=0; q[qt++]=src;
    for(int qh=0; qh<qt; qh++){
        int u =q[qh];
        for (Edge e : G[u]){
            int v=e.to;
            if(dist[v]<0 && e.f < e.cap)
                dist[v]=dist[u]+1, q[qt++]=v;
        }
    }
    return dist[dst]>=0;
}
ll dinic_dfs(int u, ll f){
    if(u==dst) return f;
    for(int &i=work[u]; i<si(G[u]); i++){
        Edge &e = G[u][i];
        if(e.cap<=e.f) continue;
        int v=e.to;
        if(dist[v]==dist[u]+1){
                ll df=dinic_dfs(v, min(f, e.cap-e.f));
                if(df>0){
                        e.f+=df, G[v][e.rev].f-= df;
                        return df;  }
        }
    }
    return 0;
}
ll maxFlow(){
    ll result=0;
    while(dinic_bfs()){
        fill(work, work+nodes, 0);
        while(ll delta=dinic_dfs(src,INF))
            result+=delta;
    }
    // todos los nodos con dist[v]!=-1 vs los que tienen dist[v]==-1 forman el min-cut
    return result; }

char m[MAXRC][MAXRC];
int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};

int main() {
        fastio;

        int r, c;
        cin >> r >> c;

        src = r*c;
        dst = r*c+1;
        nodes = r*c + 2;

        int leftCut = 0, rightCut = 0;
        forn(i, r)
            forn(j, c) {
                cin >> m[i][j];
                
                int cap = m[i][j] == '-' ? 2 : 1;
                if ((i+j)%2) { // left node
                    addEdge(src, i*c+j, cap);
                    leftCut += cap;

                    forn(k, 4) {
                        int ni = i + di[k], nj = j + dj[k];
                        if (ni >= 0 && nj >= 0 && ni < r && nj < c)
                            addEdge(i*c+j, ni*c+nj, INF);
                    }
                } 
                else {
                    rightCut += cap;
                    addEdge(i*c+j, dst, cap); // right node
                }
            }

        cout << ((leftCut == rightCut && leftCut == maxFlow()) ? 'Y' : 'N') << endl;        

        return 0;
}
