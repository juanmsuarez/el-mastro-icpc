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

const int MAXN = 1e5+10;
const double PI = acos(-1);
int a[MAXN], b[MAXN];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("input.txt","r",stdin); 
	#endif
	
	int n;

	while (cin >> n) {
		forn(i,n) cin >> a[i];

		sort(a, a+n);

		int j = 0;
		for (int i = 0; i < n; i += 2)
			b[j++] = a[i];
		
		for (int i = n%2 == 0 ? n-1 : n-2; i >= 1; i -= 2)
			b[j++] = a[i];
	
		double res = 0;
		forn(i, n)
			res += b[i]*b[(i+1)%n];	

		res *= sin(2*PI/n)/2;
		cout << fixed << setprecision(3) << res << endl;
	}

	return 0;
}
