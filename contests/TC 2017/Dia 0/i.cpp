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
	
	//#ifdef LOCAL 
	//	freopen("in.txt","r",stdin); 
	//#endif
	
	int n = 0;
	while(cin >> n && n != -1){
		int s = 0, r = 0, x;
		int N = n;
		while(N--){
			cin >> x;
			s += x;
			if(s % 100 == 0){
				s = 0;
				r++;
			}
		}
		cout << r << '\n';
	}

	return 0;
}
