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


struct event {
	int i, j, t;
};

event a[MAXM];

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
			a[t] = event();
			cin >> a[t].i >> a[t].j;
			a[t].t = t;
		}
	
		sort(a, a+m, [] (event &a, event &b) {
			return a.j > b.j || (a.j == b.j && a.i < b.i) || (a.j == b.j && a.i == b.i && a.t > b.t);
		});
		
		int last = n, t = m, res = m;
		// y si no contiene al ultimo?
		
		forn(i, m) {
			//cerr << "miro " << a[i].i << ' ' << a[i].j << endl;
			//cerr << "last es: " << last << endl;
			if (a[i].i < last && a[i].j >= last && a[i].t < t) {
				last = a[i].i;
				t = a[i].t;
			}
			else res--; 
		}
	
		cout << res << endl;
	
		if (nc) cout << endl;
	}

	return 0;
}
