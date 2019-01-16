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

const int MAXN = 16, INF = 1<<30;
tint k, n, x[MAXN+10], y[MAXN+10], memo[(1<<MAXN)+10], precomp[(1<<MAXN)+10];

tint cuentita(int mask) {
	tint lx = INF, ly = INF, hx = 0, hy = 0;
	forn(i, n)
		if (mask & (1<<i)) {
			//cout << "entre " << endl;
			lx = min(lx, x[i]);
			ly = min(ly, y[i]);
			hx = max(hx, x[i]);
			hy = max(hy, y[i]);
		}
	//cout << lx << ' ' << ly << ' ' << hx << ' ' << hy << endl;
	return 2*(hx + k - (lx - k)) + 2*(hy + k - (ly - k));
}

tint dp(int mask) {
	if (mask == 0) return 0;
	
	tint &res = memo[mask];
	if (res != INF) return res;
	
	int i = mask;
	while (i > 0) {
		//cout << "tengo "; printmask(mask); cout << " y agarro "; printmask(i); cout << " me cuesta " << cuentita(i) << endl;
		res = min(res, dp(mask & ~i) + precomp[i]);
		i = (i-1) & mask;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	cin >> k >> n;
	
	fill(memo, memo+(1<<n), INF);
	
	forn(i, n) cin >> x[i] >> y[i];
	
	forn(i, 1<<MAXN) precomp[i] = cuentita(i);
	
	cout << dp((1<<n)-1) << endl;

	return 0;
}
