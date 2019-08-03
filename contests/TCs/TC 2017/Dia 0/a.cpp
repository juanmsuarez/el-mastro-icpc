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
 
int a[550];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif

	int N;
	cin>>N;
	while(N!=-1){
		for(int i=1;i<=N;i++) cin>>a[i];
		bool res=true;
		for(int i=1;i<=N;i++){
			if(a[i]>i&&a[i]!=0) res=false;
		}
		if(!res){
			cout<<"N"<<endl;
			cin>>N;
			continue;
		}
		for(int i=1;i<=N;i++){
			if(a[i]==i){
				for(int j=1;j<i;j++) a[j]++;
				a[i]=0;
				i=0;
			}
		}
		for(int i=1;i<=N;i++){
			if(a[i]!=0) res=false;
		}
		if(!res){
			cout<<"N"<<endl;
			cin>>N;
			continue;
		}
		cout<<"S"<<endl;
		cin>>N;
	}
	return 0;
}
