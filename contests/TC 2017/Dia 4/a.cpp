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

const double mypi=3.14159265358979323846, eps = 1e-9;




int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif

	tint R,r, res;
	while(cin>>R>>r){
		if(r>R){
			res =0;
		} else if(r*2>R){
			res=1;
		} /*else if(7*C>3*T){
			res=2;
		} */else {
			for(res=3;r - eps <= sin(mypi/res)*(R-r);res++);//cerr << sin(mypi/(res))*(R-r) << endl;
		} 
		
		if (res == 0) cout << "Coin cannot fit in tray." << endl;
		else if (res == 1) cout << "1 coin of size " << r << " will fit the inner rim of a tray of size " << R<< "." << endl;
		else cout << res-1 << " coins of size " << r << " will fit the inner rim of a tray of size " << R << "." << endl;
	}
	return 0;
}
