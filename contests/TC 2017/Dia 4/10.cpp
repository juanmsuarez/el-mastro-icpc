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

const int MAXN = 100+10;
int cnt, a[MAXN][MAXN];
vi adj[MAXN];

int build(int i, int j) {
	if (i == j) return cnt++;
	
	int m = a[i][j]-1;
	
	int r = cnt++;
	if (i <= m-1) adj[r].pb(build(i,m-1));
	if (m+1 <= j) adj[r].pb(build(m+1,j));
	
	return r;
}

int height(int u) {
	int mx = 0;
	
	forn(i,si(adj[u])) {
		int v = adj[u][i];
		mx=max(mx,height(v));
	}
	mx++;
	return mx;
}

int sumdepth(int u, int d = 1) {
	int sum = 0;
	forn(i,si(adj[u])) {
		int v = adj[u][i];
		sum += sumdepth(v, d+1);
	}

	return sum+d;
}

int main() {
	//ios_base::sync_with_stdio(false); 
	//cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int n, nc = 1;
	while (cin >> n && n != -1) {
		cnt = 0;
		forn(i,n-1)adj[i].clear();
		forn(i,n) {
			int _;
			cin >> _;
			forn(j,n-1) cin >> a[i][j];
		}
		
		build(0,n-2);
		
		cout << "Case " << nc++ << ":" << endl;
		cout << "The height of the BST is: " <<  height(0) << endl;
		cout << "The average of the search in the BST is: " << fixed << setprecision(2) << double(sumdepth(0)) / (n-1) << endl;
	}

	return 0;
}
