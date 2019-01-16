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

int raiz(int n){
	int res;
	for(res=1;res*res<n;res++);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	char a[2]={'@', '.'};
	int b, w;
	cin>>b>>w;
	if(b==w){
		cout<<b+w<<" "<<1<<endl;
		for(int i=0;i<b+w;i++) cout<<a[i%2]<<endl;
	} else {
		if(b>w){
			swap(b, w);
			swap(a[0], a[1]);
		} 
		cerr<<raiz(w-b+1)<<endl;
		int aux=raiz(w-b+1);
		int c=aux*2+1;
		int f=aux*2+1+2*(b-1);
		cout<<f<<" "<<c<<endl;
		int cont=(w-b)+1;
		for(int i=0;i<aux*2+1;i++){
			for(int j=0;j<c;j++){
				if((i%2==0)||(j%2)==0) cout<<a[0];
				else{
					if(cont>0){
						cont--;
						cout<<a[1];
					} else cout<<a[0];
				}
			}
			cout<<endl;
		}
		for(int i=0;i<2*(b-1);i++){
			for(int j=0;j<c;j++) cout<<a[(i+1)%2];
			cout<<endl;
		}
		//cout<<f*c<<endl;
	}
	
	return 0;
}
