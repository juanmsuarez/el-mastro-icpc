#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int m = INT_MAX, N = 2e3+1;
int t[N][N], a[N];

int dp(int x, int y, int i){
	if(t[x][y]) return t[x][y];
	int r;
	if(a[i] > x){
		if(a[i] < y)
	}
}

int main() {
    fastio;
	int n; cin >> n;
	int a,b; cin >> a >> b;
	forn(i,n-1) cin >> a[i];
	cout << dp(a,b,0) << endl;
    return 0;
}
