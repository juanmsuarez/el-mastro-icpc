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
	
	tint W, H, w, h;
	cin >> W >> H >> w >> h;

	if(W>H) swap(W, H);
	if(w>h) swap(w, h);
	if(W<w||H<h){	
		cout<<-1<<endl;
		return 0;
	}
	tint i, j;
	for(i=0;(1LL<<i)*w<W;i++);
	for(j=0;(1LL<<j)*h<H;j++);
	if(W>=h){
		tint k, l;
		for(k=0;(1LL<<k)*w<H;k++);
		for(l=0;(1LL<<l)*h<W;l++);
		cout<<min((k+l), (i+j))<<endl;
	} else {
		cout<<i+j<<endl;
	}
	return 0;
}
