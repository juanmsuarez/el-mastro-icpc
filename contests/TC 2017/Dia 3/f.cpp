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

bool a[5100];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int N;
	cin>>N;
	while(N!=0){
		bool ent, aux=true;
		for(int i=0;i<N;i++){
			 cin>>ent;
			 if(ent==1){
				 a[i]=true;
				 aux=false;
			 }
			 else a[i]=false;
		}
		if(aux){ // juan: tal vez esto siempre de 0
			if(N==1){
				cout<<1<<endl;
			} else {
				cout<<((N+1)/2)<<endl;
			}
		} else {
			int ind;
			for(ind=0;ind<N;ind++){
				if(a[ind]) break;
			}
			int i=ind;
			int res=0;
			do{
			   if(a[i]){
				   i++; i%=N;
				   continue;
			   }
			   int l=0, j;
			   for(j=i;!a[j];j=(j+1)%N) l++;
			   res+=(l/2);
			   i=j;
		   } while(i!=ind);
		   cout<<res<<endl;
	   }
	   cin>>N;
	}

	return 0;
}
