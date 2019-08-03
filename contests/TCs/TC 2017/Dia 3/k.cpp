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

const int MAXN = 1e4+10;
vi a[MAXN];



int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int n;
	while (cin >> n && n != 0) {
		forn(i, n) {
			a[i].clear();
			
			int k;
			cin >> k;
			forn(j,k) {
				int c;
				cin >> c;
				a[i].pb(c);
			}
			sort(a[i].begin(), a[i].end());
		}
		
		int res = 1<<30;
		forn(t, 1000+1) {
			int cuenta = 0;
			
			forn(i, n) {
				int bas = 0, av = 0;
				
				if (a[i][0] >= t) av = si(a[i]);
				else if (a[i][si(a[i])-1] < t) bas = si(a[i]); 
				else {
					int lo = lower_bound(a[i].begin(), a[i].end(), t) - a[i].begin();
					bas = lo;
					av = si(a[i]) - lo;
				}
				
				cuenta += abs(bas - av);
			}
			if (cuenta < res) {
				res = cuenta;
			}
		}
		cout << res << endl;
	}

	return 0;
}
