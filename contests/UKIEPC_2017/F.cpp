#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
    #define RAYA cerr << "----------" << endl
#else
    #define DBG(a)
    #define RAYA
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAXN = 400+10;
int n, k;
double memo[MAXN][MAXN];

double dp(int coins, int flips) {
    if (flips == 0) return n - coins;

    double &res = memo[coins][flips];
    if (res != -1) return res;

    res = 0.5*dp(coins, flips-1);
    if (coins == 0) res += 0.5*dp(coins+1, flips-1);
    else res += 0.5*dp(coins-1, flips-1);

    return res;
}

int main() {
    fastio;

    cin >> n >> k;

    fill(memo[0], memo[MAXN], -1);
    cout << fixed << setprecision(6) << dp(n, k) << endl;

    return 0;
}
