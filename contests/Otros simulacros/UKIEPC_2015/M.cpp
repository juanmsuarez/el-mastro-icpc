#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
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

const int MAXN = 1e3+10;
const double EPS = 1e-9;
tint t[MAXN], x[MAXN];

int main() {
    fastio;

    int m, n;
    cin >> m >> n;
    forn(i, m) cin >> t[i];
    forn(i, n) cin >> x[i];

    set<tint> ans;
    forn(i, n-m+1) {
        //cerr << "check " << i << endl;
        bool can = true;
        //cerr << x[i+1]-x[i] << ' ' << t[1]-t[0] << endl;
        double d1 = double(x[i+1]-x[i])/(t[1]-t[0]);
        //cerr << d1 << ' ';
        forsn(j, i+1, i+m-1) {
            double d2 = double(x[j+1]-x[j])/(t[j-i+1]-t[j-i]);
            //cerr << d2 << ' ';
            if (abs(d1-d2) > EPS) {
                can = false;
                break;
            }
        }
        //cerr << endl;

        if (can) {
            //cerr << i << ' ' << x[i+1]-x[i] << endl;
            ans.insert(x[i+1]-x[i]);
        }
    }

    cout << si(ans) << endl;
    string sep;
    for(tint t : ans) {
        cout << sep << t;
        sep = " ";
    }
    cout << endl;

    return 0;
}
