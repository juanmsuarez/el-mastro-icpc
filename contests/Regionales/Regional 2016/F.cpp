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
		freopen("input.txt","r",stdin); 
	#endif
	
	int n,c,s;
	while(cin >> n >> c >> s){
		int pos =1,res=s==1;
		forn(i,c){
			int x;
			cin >>x;
			pos+=x;
			if(!pos)pos=n;
			if(pos>n)pos=1;
			if(pos==s)res++;
		}

		cout << res << endl;
	}

	return 0;
}
