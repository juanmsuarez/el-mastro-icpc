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
	
	multiset<pii> s;
	int r;
	
	while (cin >> r && r != 0) {
		if (r == 1) {
			int k, p;
			cin >> k >> p;
			
			s.insert(mp(p,k));
		}
		else if (s.empty()) cout << 0 << endl;
		else if (r == 2) {
			auto it = s.end();
			it--;
			
			cout << it->second << endl;
			s.erase(it);
		}
		else {
			auto it = s.begin();
			
			cout << it->second << endl;
			
			s.erase(it);
		}
	}

	return 0;
}
