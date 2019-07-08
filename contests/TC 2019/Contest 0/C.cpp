#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int N = 200+5, INF = 1e6;
int n, a[N], memo[N][N][N]; 

int dp(int pos, int inc, int dec) {
    if (pos == n) return 0;

    int &res = memo[pos][inc][dec];
    if (res != -1) return res;


    res = dp(pos+1, inc, dec) + 1;
    if (a[inc] < a[pos]) res = min(res, dp(pos+1, pos, dec));
    if (a[dec] > a[pos]) res = min(res, dp(pos+1, inc, pos));

    return res;
}


int main() {
	fastio;
	
    while (cin >> n && n != -1) {
        a[0] = 0; a[1] = INF+1;
        forn(i, n) cin >> a[2+i];
        n += 2; 
    
        fill(memo[0][0], memo[N][0], -1);
        cout << dp(2, 0, 1) << endl; 
    }
	
	return 0;
}
