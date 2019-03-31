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
typedef vector<vi> vvi;

const int MAXN = 200+10, MOD = 1e9+7;
vi adj[MAXN];
// dp(u, left, color, parentColored)
// ways(vistos, pinteAlguno)
int n, k, dp[MAXN][MAXN][2][2], ways[MAXN][2], waysTemp[MAXN][2];

inline int add(int x, int y) {
	if (x+y >= MOD) return x+y-MOD;
	else return x+y;
}
inline int mul(tint x, int y) {
	return x*y%MOD;
}

void calcDp(int u, int p = -1) {
	for (int v : adj[u]) if (v != p) calcDp(v, u);

	forn(color, 2) forn(parentColored, 2) {
		fill(ways[0], ways[MAXN], 0);
		ways[0][0] = 1;

		for (int v : adj[u]) {
			if (v == p) continue;

			fill(waysTemp[0], waysTemp[MAXN], 0);

			forn(send, k-color+1) {
				forn(left, k-send-color+1) {
					waysTemp[send+left][0] = add(waysTemp[send+left][0], mul(ways[left][0], dp[v][send][0][color]));

					waysTemp[send+left][1] = add(waysTemp[send+left][1], mul(add(ways[left][1], ways[left][0]), dp[v][send][1][color]));
					waysTemp[send+left][1] = add(waysTemp[send+left][1], mul(ways[left][1], dp[v][send][0][color]));
				}
			}

			forn(used, k+1) forn(pinte, 2)
				ways[used][pinte] = waysTemp[used][pinte];
		}

		forsn(used, color, k+1) {
			dp[u][used][color][parentColored] = ways[used-color][1];

			if (!color || parentColored)
				dp[u][used][color][parentColored] = add(dp[u][used][color][parentColored], ways[used-color][0]);

			//cerr << "nodo " << u << " pintando " << used << " color " << color << " padre pinto " << parentColored << " da " << dp[u][used][color][parentColored] << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("input.txt","r",stdin); 
	#endif

	while (cin >> n >> k) {
		forn(u, n) adj[u].clear();
		
		forn(_, n-1) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		calcDp(0);

		cout << add(dp[0][k][0][0], dp[0][k][1][0]) << endl;
	}

	return 0;
}
