#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MAXN = 400+10,INF=1e9;

int adj[MAXN][MAXN],
    dist[MAXN][MAXN];

int n;

vi planet;
vi temps;

struct query{
    int u,v,k,ind,res;
    bool operator <(const query& o)const{
        return k < o.k;
    }
    bool operator >(const query& o)const{
        return k > o.k;
    }
};

bool comp(int a,int b){
    return temps[a]<temps[b];
}

vi index;


void solve(vector<query>& qs){
    forn(i,n){
        forn(j,n){
            dist[i][j]=adj[i][j];
        }
        dist[i][i]=0;
    }


    int nextq=0;
    forn(ind,n){
        int k = planet[ind];
        while(nextq<si(qs)&&qs[nextq].k<index[k]){
            query& q = qs[nextq];
            int d =dist[q.u][q.v];
            if(d!=INF)
                q.res=d;
            else q.res=-1;
            nextq++;
        }
        forn(i,n){
            forn(j,n){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main() {
	fastio;

    int r;
	cin >> n >> r;
    
    planet = vi(n);
    temps = vi(n);
    forn(i,n){
        planet[i]=i;
        cin >>temps[i];
    }

    fill(adj[0],adj[MAXN],INF);
    forn(i,r){
        int u,v,d;
        cin >> u >> v >> d;
        adj[--u][--v]=d;
        adj[v][u]=d;
    }

    int cantq;
    cin >> cantq;
    vector<query> queries[2];
    forn(i,cantq){
        query q;
        int t;
        cin >> q.u >>q.v >> q.k >> t;
        q.u--;q.v--;q.k--;
        q.ind=i;
        queries[t].pb(q);
    }
    sort(all(queries[0]));
    sort(all(queries[1]));
    
    sort(all(planet),comp);
    vi tempo = temps;
    index = vi(si(planet));
    sort(all(tempo));
    tempo.erase(unique(all(tempo)),tempo.end());

    int kth=0;
    for(int p:planet){
        while(tempo[kth]<temps[p])kth++;
        index[p]=kth;
    }

    solve(queries[0]);
    reverse(all(planet));
    reverse(all(tempo));
     kth=0;
    for(int p:planet){
        while(tempo[kth]>temps[p])kth++;
        index[p]=kth;
    }
    solve(queries[1]);

    vi res(cantq);
    forn(i,2){
        for(query q:queries[i])res[q.ind]=q.res;
    }

    forn(i,si(res)){
        cout << res[i] << endl;
    }


	
	return 0;
}

