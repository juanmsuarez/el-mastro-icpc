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

tint f(tint a){
	return ((a*(a+1)*((2*a)+1))/6+((a-1)*a*((2*a)-1))/6);
}
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	/*
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	*/
	
	tint N;
	cin>>N;
	tint men=1, may=2e6, mid;
	while(may-men>1){
		mid=(may+men)/2;
		if(f(mid)>N){
			may=mid;
		} else {
			men=mid;
		}
	}
	cout<<men<<endl;
	return 0;
}
