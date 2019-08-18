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

const int N = 200, M = 1e9 + 7;

int add(int a, int b) { return a + b >= M ? a + b - M : a + b; }

map<tuple<int, vi, vi>, int> memo;

vi adv(const vi &v) {
    vi w = v;
    for (int &dif : w) dif++;
    return w;
}

int dp(int pos, const vi empty, const vi moving) {
    auto state = make_tuple(pos, empty, moving);
    if (memo.count(state)) return memo[state];
    int &res = memo[state];

    vi nempty 
    // dont move
    res = add(res, dp(pos + 1, adv(empty), adv(moving)));

    // move right
    res = add(res, dp(pos + 1, 

    // move left
    for (int dif : empty) {

    }

    return res;
}

int main() {
    fastio;

    int k; cin >> k;
    dforn(pos, N) cout << dp(pos, {}, {}) << endl;


    return 0;
}
