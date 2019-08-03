#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define eb emplace_back
#define pb push_back
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

const int MAXK = 18+2, MAXD = 10;
int k;
tint cnt[MAXK][MAXD][2];

inline bool range(int d) {
    return d > 0 && d < 10;
}

tint dp(int pos, int actual, bool up) {
    if (pos > 18 || !range(actual)) return 0;
    
    tint &res = cnt[pos][actual][up];
    if (res != -1) 
        return res;    
    res = 0;

    if (pos >= 3) res++;

    int move = up ? 1 : -1;
    for (int next = actual + move; range(next); next += move) 
        res += dp(pos+1, next, !up, v);

    return res;
}

int main() {
    fastio;

    cin >> k;

    fill(cnt[0][0], cnt[MAXK][0], -1);

    tint res = 0;
    int pre = 10;
    // casos especiales: |prefijo| <= 2. basicamente, cuando aun no hay patron
    // a seguir.
    forsn(pos, 1, k+1) {
        int a;
        cin >> a;

        forsn(d, pos > 2 && a > pre ? pre+1 : 1, a) {
            if (d == pre) continue;
            res += dp(pos, d, !(d > pre), v);
            if (pos == 1) 
                res += dp(pos, d, d > pre, v);
        }
        res += pos >= 3;

        pre = a;
    } 
    cout << res << endl;

    return 0;
}
