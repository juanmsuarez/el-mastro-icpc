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

const int MAXN = 1000+10;
string a[MAXN], b[MAXN];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif

	int n, m;
	cin >> n >> m;
	forn(i, n) cin >> a[i];
	forn(i, m) cin >> b[i];
	
	set<string> s;
	forn(i, n) {
		int mx = 0;
		forn(j, m) {
			int k = 0; 
			while (a[i][k] == b[j][k]) k++;
			mx = max(mx, k);
		}
		s.insert(a[i].substr(0, mx+1));
	}
	
	int res = 0;
	for (auto e : s)
		res += si(e);
	cout << res << endl;

	return 0;
}

