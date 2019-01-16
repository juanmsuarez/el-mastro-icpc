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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N = 1e4+5, T = 120+5, K = 5+5;

int n, d[N], c[N]; 
double memo[N][T][K];

double dp(int i, int t, int k) {
    if (i == n) return 0;

    double &res = memo[i][t][k];
    if (res != -1) return res;

    res = c[i] + dp(i+1, max(0, 120-d[i]), 5); 

    if (t > 0 && k > 0)
        res = min(res, (k == 5 ? .5 : .25)*c[i] + dp(i+1, max(0, t-d[i]), k-1));

    return res;
}

int main() {
	fastio;

    fill(memo[0][0], memo[N][0], -1);
	
    cin >> n;
    forn(i, n) cin >> d[i] >> c[i];    

    cout << fixed << setprecision(2) << dp(0, 0, 0) << endl;
	
	return 0;
}
