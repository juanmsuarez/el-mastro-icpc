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

const int MAXN = 1e7+10;
int p[MAXN];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int n;
	cin >> n;
	
	fill(p, p+MAXN, -1);
	int tot = 0;
	
	forn(i,n) {
		int a;
		cin >> a;
		while (a > 0) {
			tot++;
			p[tot]=i+1;
			a--;
		}
	}
	
	int q;
	cin >> q;
	forn(i, q) {
		int c;
		cin >> c;
		if (p[c] == -1) cout << "none" << endl;
		else cout << p[c] << endl;
	}

	return 0;
}
