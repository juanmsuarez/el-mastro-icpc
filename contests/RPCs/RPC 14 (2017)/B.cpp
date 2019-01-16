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
	
	int n;
	while(cin >> n){
		bool a[n][9];
		forn(i,n) forn(j,9) a[i][j] = 0;
		set<int> s;
		forn(i,n){
			int x; cin >> x;
			while(x != 0){
				int r = x % 10;
				x /= 10;
				a[i][r-1] = 1;
			}
		}
		forn(i,n){
			 int x = 0;
			 forn(j,9) if(a[i][j]) x = x*10 + j+1;
			 s.insert(x);
		}
		cout << s.size() << endl;
	}

	return 0;
}
