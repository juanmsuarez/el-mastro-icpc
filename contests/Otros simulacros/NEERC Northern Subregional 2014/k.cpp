// https://codeforces.com/gym/100531/problem/K
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl
#else 
    #define D(a) 8 
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define all(a) (a).begin(),(a).end()
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int M = 1e9 + 7;
int add(int a, int b){ return a+b < M ? a+b : a+b-M; }
int sub(int a, int b){ return a-b >= 0 ? a-b : a-b+M; }
int mul(ll a, ll b){ return int(a*b % M); }

const int N = 1001, T = 101, L = 251;
int l[N], r[N], dp[N][T], ways[L][L];

// dp[i][l] = number of ways to distribute dream seconds from the i-th kebab and the last dream to distance l+1
// ways[w][d] = number of ways to distribute at most d dream seconds in a window of w seconds where a dream can happen in any second

int main() {
    fastio;

    #ifndef LOCAL
        freopen("kebab.in", "r", stdin);
        freopen("kebab.out", "w", stdout);
    #endif

    int n, t; cin >> n >> t;
    forn(i, n) cin >> r[i] >> l[i]; 
    
    forn(d, L) ways[d][0] = 1;
    forn(w, L) ways[0][w] = 1;
    forsn(d, 1, L) forsn(w, 1, L) 
        ways[d][w] = add(ways[d][w-1], ways[d-1][max(w-1-t, 0)]);
    
    forn(i, t+1) dp[n][i] = 1;
    dforn(i, n) forn(j, t+1) {
        int &x = dp[i][j] = dp[i+1][min(t, j + r[i])];

        int left = r[i] - (t-j) - 1;
        if (left < 0 || l[i] == r[i]) continue;    

        int win = left - t;
        int d = r[i] - l[i] - 1;
        forn(k, left + 1) x = add(x, mul(ways[d][max(0, win-k)], dp[i+1][min(k, t)])); 
    }

    cout << dp[0][t] << endl;
    return 0;
}
