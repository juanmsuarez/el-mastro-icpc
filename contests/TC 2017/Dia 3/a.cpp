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

const int MAXN =1e3+10, INF = 1<<30;
string s;
int n, memo[MAXN][30];

int dist(int a, int b) {
	return min((a-b+26)%26, (b-a+26)%26);
}

int dp(int p, int carry) {
	if (p == n) return 0;
	
	int &res = memo[p][carry];
	if (res != INF) return res;
	
	forsn(m, -25,26) {
		int c = s[p] - 'a', act = (m + 26) % 26, distRest = dist(act, c);
		res = min(res, act + distRest + min(dp(p+1, carry+act), dp(p+1, act)));
	}
	
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif

	while (cin >> s && s != "*") {
		n = si(s);
		fill(memo[0], memo[n], INF); 
		cout << dp(0, 0) << endl;
	}
	
	return 0;
}
