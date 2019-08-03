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
	
	int c; cin >> c;
	while(c--){
		string n, K; cin >> n >> K;
		int fibo[50];
		fibo[0] = 1;
		fibo[1] = K[K.size()-1] - '0';
		
		int k = fibo[1];
		if(fibo[1] == 0) cout << 0 << endl;
		else if(fibo[1] == 1) cout << 1 << endl;
		else{
			forsn(i,2,50) fibo[i] = (fibo[i-1] * fibo[i-2]) % 7;
			int r = 0, si = int(n.size()), m;
			if(k == 2 || k == 4) m = 11;
			else if(k == 3 || k == 5) m = 33;
			else m = 3;
			for(int i = 0; i < si; i++) r = (r * 7 + n[i] - '0') % m;
			int x = (r / 10) * 7 + r % 10;
			cout << fibo[x] << endl;
		}
	}
	return 0;
}

