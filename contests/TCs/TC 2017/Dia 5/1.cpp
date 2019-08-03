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

tint A[12000][12000];
tint est[12000];
tint MAXN=(1LL<<(62));
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	tint C, N;
	while(cin>>C>>N){
		for(int i=1;i<=N;i++){
			for(int j=i;j<=N;j++) cin>>A[i][j];
		}
		for(int i=N;i>0;i--){
			tint aux=MAXN; 
			for(int j=i;j<N;j++) aux=min(aux, est[j+1]+A[i][j]+C);
			aux=min(aux,A[i][N]);
			est[i]=aux;
		}
		//for(int i=1;i<=N;i++) cout<<i<<" "<<est[i]<<endl;
		cout<<est[1]+C<<endl;
		
	}
	return 0;
}
