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

const int MAXN = 1e9+10;

bool isPrime(int n) {
	if (n <= 1) return false;

	for (int i = 2; i*i <= n; i++)
		if (n%i==0)
			return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("input.txt","r",stdin); 
	#endif
	
	int n;
	while (cin >> n)
		dforsn(i, 2, n+1)
			if (isPrime(i)) {
				cout << i << endl;
				break;
			}

	return 0;
}
