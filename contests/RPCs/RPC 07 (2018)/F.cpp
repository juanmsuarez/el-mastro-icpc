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
typedef long long int ll;

const int MAXM = 20;
int m, c[MAXM];
vector<vi> memo;

int dp(int act, int mask) {
    if (mask == (1<<m)-1) return 0;

    int &res = memo[act][mask];
    if (res != -1) return res;
    res = 0;

    int sum = 0;
    forn(i, m)
        if (mask & (1<<i))
            sum += c[i];

    forn(next, m) 
        if (!(mask & (1<<next))) {
            int dpNext = dp(next, (mask | (1<<next)));
            res = max(res, dpNext + (sum + c[next] == 0));
        }

    return res;
}

int main() {
    fastio;

    int n;
    cin >> m >> n;

    while (n--) {
        int a, b, p;
        cin >> a >> b >> p;
        c[a] += p;
        c[b] -= p;
    }

    memo = vector<vi>(m, vi(1<<m, -1));

    int mx = 0;
    forn(start, m) mx = max(mx, dp(start, (1<<start)) + (c[start] == 0));
    cout << m - mx << endl;

    return 0;
}
