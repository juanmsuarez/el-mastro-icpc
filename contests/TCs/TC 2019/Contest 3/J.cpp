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

const int N = 400;
int memo[N][N][2];
vi base, act;

bool dp(int pos, int sum, bool greater = false) {
    if (pos == -1) return sum == 0 && greater;
    if (sum < 0) return false;

    int &res = memo[pos][sum][greater];
    if (res != -1) return res;
    res = false;

    forn(d, 10) {
        if (!greater && d < base[pos]) continue;

        int npos = pos-1, nsum = sum - d, ngreater = greater || d > base[pos];
        if (dp(npos, nsum, ngreater)) {
            act[pos] = d;
            res = true;
            break;
        }
    }

    return res;
}

bool dodp(int pos, int sum) {
    fill(memo[0][0], memo[N][0], -1);
    return dp(pos, sum);
}

int main() {
	fastio;

    base = act = vi(1);

    int n; cin >> n;
    int start = 0;
    forn(i, n) {
        int sum; cin >> sum;

        while (!dodp(start, sum)) base.pb(0), act.pb(0), start++;
    
        base = act;
        reverse(all(act));
        for (int d : act) cout << d;
        cout << endl;
    }
	
	return 0;
}
