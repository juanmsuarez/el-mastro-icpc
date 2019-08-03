#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) ((int)(a).size())
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const tint MAXN = 500+10, INF = 1<<30;
tint n, m, arco[MAXN][MAXN], arcoT[MAXN][MAXN], distS[MAXN], distD[MAXN];
bool  vis[MAXN];

void dijkstra(int s, tint a[][MAXN], tint d[]) {
	fill(d, d+n, INF);
	fill(vis, vis+n, false);
	
	d[s] = 0;
	while (true) {
		int umin = -1, mn = INF;
		forn(u, n) if (!vis[u] && d[u] < mn ) {
			mn = d[u];
			umin = u;
		}
		
		//cout << "llegue a " << umin << " con min dist " << d[umin] << endl;
		
		if (umin == -1) break;
		vis[umin] = true;
		
		forn(v, n)
			if (d[umin] + a[umin][v] < d[v])
				d[v] = d[umin] + a[umin][v];
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif

	while (cin >> n >> m && n != 0) {
		//cout << "CASO "<< endl;
		int s, d;
		cin >> s >> d;
		
		fill(arco[0], arco[n], INF);
		fill(arcoT[0], arcoT[n], INF);
		forn(u, n) arco[u][u] = arcoT[u][u] = 0;
		
		forn(i, m) {
			int u, v, p;
			cin >> u >> v >> p;
			arco[u][v] = p;
			arcoT[v][u] = p;
		}
		
		dijkstra(s, arco, distS);
		dijkstra(d, arcoT, distD);
		
		/*
		forn(u, n)
			forn(v, n)
				cerr << "min dist " << u << ' ' << v << " es " << dist[u][v] << endl;
		*/
		/*
		forn(u, n) {
			cout << "a " << u << endl;
			cout << "desde s " << distS[u] << endl;
			cout << "hasta d " << distD[u] << endl;
		}*/
		
		forn(u, n)
			forn(v, n) {
				//cout << u << ' ' << v << endl;
				//cout << distS[u] << ' ' << arco[u][v] << ' ' << distD[v] << endl;
				if (u != v && distS[u] + arco[u][v] + distD[v] == distS[d]) {
					//cout << u << ' ' << v << " parte de camino min "<< endl;
					arco[u][v] = INF;
				}
			}
		
		dijkstra(s, arco, distS);
		
		cout << (distS[d] == INF ? -1 : distS[d]) << endl;
	}

	return 0;
}
