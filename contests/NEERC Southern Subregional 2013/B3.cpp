#include <bits/stdc++.h> 
using namespace std;

#define fastio         ios_base::sync_with_stdio(0); cin.tie(0);
#define ford(i,s,n)    for(int i = int(n-1) ; i >= int(s) ; i--)
#define fors(i,s,n)    for(int i = int(s) ; i < int(n) ; i++)
#define forn(i,n)      for(int i = 0 ; i < int(n) ; i++)
#define D(a)           cerr << #a << " = " << a << endl; 
#define all(a)         a.begin(),a.end()  
#define sz(a)          int((a).size())
#define eb             emplace_back
#define mp             make_pair
#define ss             second
#define ff             first
#define endl           '\n'
typedef long long int  ll;
typedef vector<int>    vi;
typedef pair<int,int>  pii;

const int M = 1e7+1, N = 3e5;
pii *c[M];
int r[N];

int main() {
	fastio;
	
	int m,n,d; 
	cin >> m >> n >> d;
	d *= 10;
	int min = 1e8, max = 0;
	forn(i,m){
		string s; cin >> s;
		int v = 0;
		forn(j,sz(s)) if(s[j] != '.') v = v*10 + s[j] - '0';
		c[v] = new pii(v,v);
		if(v < min) min = v;
		if(v > max) max = v;
	}
	forn(i,n){
		string s; cin >> s;
		int v = 0;
		forn(j,sz(s)) if(s[j] != '.') v = v*10 + s[j] - '0';
		r[i] = v;
	} 
	int x = sqrt(d*d - 100), p = min;
	fors(i, min+1, max+1) if(c[i] != NULL){
		fors(j,p+1,i) c[j] = new pii(p,i);
		p = i;
	}
	ll t = 0, y; p = min;
	forn(i,n) if(abs(r[i]-p) > x){
		if(p < r[i]) y = c[r[i]-x]->second;
		else y = c[r[i]+x]->first;
		t += abs(p-y);
		p = y;
	} 
	cout << t / 10 << '.' << t % 10 << endlessly;
	return 0;
}