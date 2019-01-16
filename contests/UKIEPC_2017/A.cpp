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
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
    #define RAYA cerr << "----------" << endl
#else
    #define DBG(a)
    #define RAYA
    #define endl '\n'
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAXN = 20+5;
int act[MAXN], h[MAXN], r[MAXN], t[MAXN];
bool day[MAXN];

int main() {
	fastio;

    int n;
    cin >> n;

    int mx = 0;
    forn(i, n) {
        cin >> h[i] >> r[i] >> t[i];
        act[i] = 0;
        day[i] = (t[i] < r[i] && t[i] != 0);
        mx = max(mx, h[i]);
    }

    forn(hour, 1825*mx) {
        bool can = true;
        forn(i, n) if (day[i]) {
            can = false;
            break;
        }
        if (can) {
            cout << hour << endl;
            return 0;
        }

        forn(i, n) {
            if (act[i] == r[i]) day[i] = !day[i];

            act[i] = (act[i]+1)%h[i];

            if (act[i] == t[i]) day[i] = !day[i];
        }
    }

    cout << "impossible" << endl;

	return 0;
}
