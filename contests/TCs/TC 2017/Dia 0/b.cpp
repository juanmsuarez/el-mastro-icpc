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
	int N,a,b;
	cin>>N;
	while(N!=(-1)){
		int res=0;
		for(a=1;a<=N;a++){
			for(b=1;b<=a;b++){
				if(a*b>N) break;
				if(((N-a*b)%(a+b))==0){
					int c=(N-a*b)/(a+b);
					if(c<=b&&(a*b+a*c+b*c==N)) res++;
				}
			}
		}
		cout<<res<<endl;
		cin>>N;
	}
	return 0;
}
