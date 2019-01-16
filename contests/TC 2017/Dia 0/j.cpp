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
	int N, P,z,s,c;
	vi costos;
	cin>>N>>P;
	for(int i=0;i<N;i++){
		cin>>z>>s>>c;
		int ci=(((z+9)/10)-s)*c;
		if(ci<0) ci=0;
		costos.pb(ci);
	}
	sort(costos.begin(), costos.end());
	int res=0;
	for(res=0;res<costos.size();res++){
		if(costos[res]>P) break;
		P-=costos[res];
	}
	cout<<res<<endl;
	return 0;
}
