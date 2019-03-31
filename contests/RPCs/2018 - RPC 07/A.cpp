#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define sz(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long int ll;

#define INF 1e9
int n,m;
double r;
int N;
#define MAX_V 250001
#define fst first
#define snd second
int ind(ii p){
    return p.first*(n+1)+p.second;
}

int dx[] = { 0,+1, 0,-1};
int dy[] = {-1, 0,+1, 0};

double dst(int k,int y){
    if(k%2==0)return r/(double)n;
    return acos(-1)*r*y/(double)(m*n);
}

bool valid(ii v){
    return 0<=v.fst && v.fst <= m && 0<=v.snd && v.snd<=n;
}

double dijkstra(ii s, ii t){//O(|E| log |V|)
	priority_queue<pair<double,ii>, vector<pair<double,ii>>, greater<pair<double,ii>> > Q;
	vector<double> dist(N, INF);
	Q.push(make_pair(0, s)); dist[ind(s)] = 0;
    //vector<ii> dad(N, mp(-1,-1));
	while(sz(Q)){
		ii p = Q.top().snd; Q.pop();
		if(p== t) break;
        forn(k,4){
            ii v = mp(p.fst+dx[k],p.snd+dy[k]);
			if(valid(v)&&dist[ind(p)]+dst(k,v.snd) < dist[ind(v)]){
				dist[ind(v)] = dist[ind(p)] + dst(k,v.snd);
				//dad[ind(v)] = p;
				Q.push(mp(dist[ind(v)], v));	}
        }
	}
	/*if(dist[ind(t)]<INF)//path generator
		for(ii i=t; i!=mp(-1,-1); i=dad[ind(i)]){
			printf("%d %d\n", i.fst,i.snd);
            printf("%f\n", dist[ind(i)]);
        }*/
	return dist[ind(t)];
}
int main() {
    fastio;

    cin >> m >> n>>r;
    N=(n+1)*(m+1)+10;

    ii a,b;
    cin >>a.fst >> a.snd >> b.fst >> b.snd;

    cout <<fixed << setprecision(8) << dijkstra(a,b)<<endl;

    return 0;
}
