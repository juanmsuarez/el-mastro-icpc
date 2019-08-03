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
    #define RAYA cerr << "----------" << endl
#else
    #define DBG(a)
    #define RAYA
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAXN = 1e3+10;
int mx, m, h;
int d[MAXN], mn[MAXN], mark[MAXN];

bool canMove(int i) {
    int pos = d[mark[i]], move = d[mark[i]+1] - d[mark[i]];

    if (i+1 < h) {
        int nxtPos = d[mark[i+1]];
        if (nxtPos - (pos+move) < max(mn[i], mn[i+1])) 
            return false;
    }
    if (i-1 >= 0) {
        int prevPos = d[mark[i-1]];
        if (pos+move - prevPos > mx)
            return false;
    }

    return true;
}

int main() {
    fastio;

    cin >> mx >> m;
    forn(i, m) cin >> d[i];
    cin >> h;
    int htemp = h;

    int extra = 0;
    forn(i, h) {
        cin >> mn[i] >> mark[i];
        mark[i]--;

        if (mark[i] == m-1) extra++;
    }

    h -= extra;

    set<int> s;
    forn(i, h)
        if (canMove(i))
            s.insert(i);

    vi ans;
    while (!s.empty()) {
        int i = *s.begin();

        ans.pb(i);
        mark[i]++;

        if (mark[i] == m-1) {
            s.erase(s.begin());
            h--;
        }
        else if (!canMove(i)) 
            s.erase(s.begin());

        if (i-1 >= 0 && canMove(i-1))
            s.insert(i-1);
        if (i+1 < h && canMove(i+1))
            s.insert(i+1);
    }

    bool could = true;
    int h = htemp;
    forn(i, h)
        if (mark[i] != m-1)
            could = false;

    if (could) { 
        forn(i, si(ans)) {
            if (i) cout << ' ';
            cout << ans[i]+1;
        }
        cout << endl;
    }
    else cout << "impossible" << endl;

    return 0;
}
