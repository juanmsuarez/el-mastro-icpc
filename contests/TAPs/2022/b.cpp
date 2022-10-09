#include <bits/stdc++.h>
using namespace std;

#define fastio cin.sync_with_stdio(0), cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)

#define all(a) (a).begin(),(a).end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int, int>;
using vi = vector<int>;
using ll = long long;

const int N = 3, B = 30, M = 1e9 + 7;
int add(int x, int y) { return x+y >= M ? x+y-M : x+y; }
int sub(int x, int y) { return x >= y ? x-y : x-y+M; }
int mul(ll x, ll y) { return int(x*y % M); }
int pot(int b, int e) {
    int r = 1;
    while (e) {
        if (e & 1) r = mul(r, b);
        e >>= 1, b = mul(b, b);
    }
    return r;
}
int inv(int x) { return pot(x, M-2); }
int divide(int x, int y) { return mul(x, inv(y)); }

bool fixed[N][B], xor_zero[8];
int l[N], r[N], dp[4][4][4][B];

int main() {
    fastio;

    forn(i, N) cin >> l[i] >> r[i];

    dforn(i, B) forn(j, N) {
        int bit = 1 << i;
        fixed[j][i] = (i==B-1 || fixed[j][i+1]) && ((r[j] & bit) == (l[j] & bit));
    }

    forn(i, 8) xor_zero[i] = __builtin_popcount(i) % 2 == 0;

    forn(i, B) forn(m0, 4) forn(m1, 4) forn(m2, 4) {
        int &x = dp[m0][m1][m2][i];

        forn(b, 8) if (xor_zero[b]) {
            forn(j, 3) if (fixed[j][i] && ((b & (1 << j)) == 0) != ((l[j] & (1 << i)) == 0)) continue;
        }
    }

    int zero = 0;
    

    int total = mul(r[0]-l[0]+1, mul(r[1]-l[1]+1, r[2]-l[2]+1));
    int ans = divide(sub(total, zero), total);
    return 0;
}
