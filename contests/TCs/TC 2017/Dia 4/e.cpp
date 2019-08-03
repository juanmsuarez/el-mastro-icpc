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

const int MAXM = 5e5+10;
pii a[MAXM];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int nc;
	cin >> nc;
	
	while (nc--) {
		int n, m;
		cin >> n >> m;
		
		forn(t, m) {
			int i, j;
			cin >> i >> j;
			a[t] = mp(i,j);
		}
		
		int last = n, res = m;
		// y si no contiene al ultimo?
		
		dforsn(i, 0, m) {
			//cerr << "miro " << a[i].first << ' ' << a[i].second << endl;
			//cerr << "last es: " << last << endl;
			if (a[i].first < last && a[i].second >= last) last = a[i].first;
			else res--; 
		}
	
		cout << res << endl;
	
		if (nc) cout << endl;
	}

	return 0;
}
