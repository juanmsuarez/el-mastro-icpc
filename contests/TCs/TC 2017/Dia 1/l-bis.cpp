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

const int MAXN = 1e6+10;
double a[MAXN];
bool b[MAXN];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	int N;
	while(cin>>N){
		forn(i, N) cin>>a[i];
		b[0]=true;
		forn(i, N-1){
			if(a[i+1]-a[i]>1) b[i+1]=true;
			else b[i+1]=false;
		}
		int res=0;
		b[N-1]=true;
		for(int i=0;i<N;i++){
			if(b[i]){ 
				int j;
				for(j=i+1;!b[j];j++)
				res+=ceil(a[j]-a[i]);
				cout<<i<<" "<<j<<endl;
				i=j-1;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
				
		
	
