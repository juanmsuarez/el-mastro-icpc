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
const int MOD = 1e9+7;
int memo[110000][16];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	int W;
	cin>>W;
	memo[W][15]=1;
	for(int i=0;i<15;i++) memo[W][i]=0;
	for(int i=W-1;i>=0;i--){
		for(int j=0;j<0x10;j++){
			int res=0;
			int act=0xF-j;
			if(act==0) res=(res+memo[i+1][0xF])%MOD;
			for(int k=3;k<16;k*=2) if((act&k)==0) res=(res+memo[i+1][act+k])%MOD;
			res=(res+memo[i+1][act])%MOD;
			memo[i][j]=res;
		}
	}
	cout<<memo[0][0xF]<<endl;			
	return 0;
}

	
