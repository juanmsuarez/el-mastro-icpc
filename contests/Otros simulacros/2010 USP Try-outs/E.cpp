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

const int N = 200, K = 6, MASK = 1 << 6;
const int MOD = 1e9 + 7;

int k;
int memo[N][MASK][MASK];

int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }

bool valid(int difs) { return difs < (1 << k); }

bool check(int difs, int pos) { return difs & (1 << pos); }

int adv(int difs) { return difs << 1; }
int rem(int difs, int pos) { return difs ^ (1 << pos); }
int add(int difs) { return difs | 1; }

int dp(int pos, int empty = 0, int moving = 0) {
    if (!valid(empty) || !valid(moving)) return 0;
    if (pos == N) return empty == 0 && moving == 0;

    int &res = memo[pos][empty][moving];
    if (res != -1) return res;
    res = 0;

    // dont move
    res = add(res, dp(pos + 1, adv(empty), adv(moving)));

    // move left and leave empty
    forn(to, 6) if (check(empty, to)) 
        res = add(res, dp(pos + 1, add(adv(rem(empty, to))), adv(moving)));

    // move left and fill
    forn(to, 6) if (check(empty, to)) 
        forn(from, 6) if (check(moving, from))
            res = add(res, dp(pos + 1, adv(rem(empty, to)), adv(rem(moving, from))));

    // move right and leave empty
    res = add(res, dp(pos + 1, add(adv(empty)), add(adv(moving))));

    // move right and fill
    forn(from, 6) if (check(moving, from))
        res = add(res, dp(pos + 1, adv(empty), add(adv(rem(moving, from)))));

    return res;
}

int main() {
    fastio;

    fill(memo[0][0], memo[N][0], -1);

    cin >> k;
    dforn(pos, N) cout << dp(pos) << endl;

    return 0;
}
