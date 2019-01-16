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
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN = 8, MAXS = (1<<MAXN) + 10, MAXM = 1e5+10, MOD = 1e9;
int n, m, memo[MAXM][MAXS];
int ways[MAXS][MAXS];

int add(int a, int b) {
    if (a+b >= MOD) return a+b-MOD;
    return a+b;
}

int mult(int a, int b) {
    return ((ll)a*b)%MOD;
}

void go(int mask, int pos = 0, int nmask = 0) {
    if (pos == n) ways[mask][nmask]++;
    else if ((1<<pos) & mask) go(mask, pos+1, nmask);
    else {
        go(mask, pos+1, nmask);

        go(mask, pos+1, (nmask | (1<<pos)));

        if (pos+2 <= n && !(mask & (1<<(pos+1)))) 
            go(mask, pos+2, nmask);
    }
}

int dp(int p, int mask) {
    if (p == m) return mask == 0;

    int &res = memo[p][mask];
    if (res != -1) return res;
    res = 0;

    forn(nmask, 1<<n)
        res = add(res, mult(ways[mask][nmask], dp(p+1, nmask)));

    return res;
}

int main() {
    fastio;

    cin >> n >> m;
    
    forn(mask, 1<<n) 
        go(mask);

    cerr << 1 << endl;
    fill(memo[0], memo[m], -1);
    map<int, bool> vis;
    dforsn(p, 0, m+1) {
        int ans = dp(p, 0);
        if (vis[ans]) {
            cout << m-p << ' ' << ans << endl;
        }
        vis[ans] = true;
    }
    cout << si(vis) << endl;

    return 0;
}
