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
typedef vector<pii> vii;

const int MAXN = 1e5+10;
const tint MOD = 1e9+7;
int f[MAXN], adj[MAXN][2], memo[MAXN][2+2][2+2];

bool nand(bool x, bool y) {
	return !(x && y);
}

int add(int x, int y) {
	if (x+y >= MOD) return x+y-MOD;
	else return x+y;
}

int mult(tint x, tint y) {
	return (x*y)%MOD;
}

int dp(int u, bool target, bool error) {
	if (u == 0) return error == false;	
	if (f[u] != -1 && target != f[u]) return 0;

	int &res = memo[u][target][error];
	if (res != -1) return res;
	res = 0;

	forn(a, 2) forn(b, 2) forn(errA, 2) forn(errB, 2)
		if (nand(a^errA, b^errB) == (target ^ error) && (nand(a, b) == target || f[u] == target))
			res = add(res, mult(dp(adj[u][0], a, errA), dp(adj[u][1], b, errB)));

	return res;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	int n;
	cin >> n;

	forsn(i, 1, n+1)
		cin >> adj[i][0] >> adj[i][1] >> f[i];

	fill(memo[0][0], memo[MAXN][0], -1);

	cout << add(dp(1, true, true), dp(1, false, true)) << endl;

	return 0;
}
