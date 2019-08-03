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

const int MAXN = 1e6+10;
double a[MAXN];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	int n;
	while (cin >> n) {
		double last = -1;
		int cnt1 = 0, cnt2=0; 
		forn(i, n) cin >> a[i];
		sort(a,a+n);
		forn(i,n) {
			if (last == -1 || a[i]-last>1) {
				last = a[i];
				cnt1++;
			}
		}
		
		last = -1;
		dforsn(i,0,n) {
			if (last == -1 || last-a[i]>1 ) {
				last = a[i];
				cnt2++;
			} 
		}
		
		cout << min(cnt1,cnt2) << endl;
	}

	return 0;
}

