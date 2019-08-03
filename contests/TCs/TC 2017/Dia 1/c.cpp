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

int e[100000];

long long int prob(long long int n){
	if(n<100000){
		if(e[n]!=-1){
			return e[n];
		}
	}
	long long int res=0;
	for(int i=2;i*i<=n;i++){
		int s=2;
		if(n%i!=0) continue;
		if(i*i==n) s=1;
		res+=s*prob(i)*prob(n/i);
		
	}
	if(n<100000){
		 e[n]=res;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	for(int i=2;i<100000;i++){
		if(e[i]==-1) continue;
		e[i]=1;
		for(int j=2;j*i<100000;j++) e[j*i]=-1;
	}
	long long int N, T;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		cout<<prob(N)<<endl;
	}
	return 0;
}
