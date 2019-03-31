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
typedef long long int tint;

const double INF = 1e19, MAXN = 1e5+10;

pii a[MAXN], b[MAXN];

double dist(pii a, pii b) {
    
}

int main() {
    fastio;

    int n, m;
    cin >> n;
    forn(i, n) cin >> a[i].first >> a[i].second;
    cin >> m;
    forn(i, m) cin >> b[i].first >> b[i].second;

    double d = INF;
    forn(i, min(n, m)) {
        d = min(d, dist(a[i], b[i]));
    }

    cout << fixed << setprecision(5) << d << endl;

    return 0;
}
