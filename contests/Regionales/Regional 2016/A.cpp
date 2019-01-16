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

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("input.txt","r",stdin); 
	#endif

	int a[4];
	while (cin >> a[0] >> a[1] >> a[2] >> a[3]) {
		int mn = 1e5;
		forn(i, 3)
			forsn(j, i+1, 4) {
				int sa = a[i] + a[j], sb = 0;

				forn(k, 4)
					if (k != i && k != j)
						sb += a[k];

				mn = min(mn, abs(sa-sb));
			}

		cout << mn << endl;
	}

	return 0;
}
