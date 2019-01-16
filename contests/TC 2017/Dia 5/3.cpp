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
		freopen("in.txt","r",stdin); 
	#endif
	
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		
		int x = 0;
		bool unos = true;
		forn(i, n) {
			int a;
			cin >> a;
			
			x ^= a;
			if (a != 1) unos = false;
		} 
		
		if ((unos && x == 0) || (!unos && x != 0)) cout << "John" << endl;
		else cout << "Brother" << endl;
	}

	return 0;
}
