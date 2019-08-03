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
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
    #define cerr  false && cerr
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int INF = 5e8+1;

int t, k;
vi a, b;

ll cost(int left) {
    ll c = (ll)abs(left)*k;

    forn(i, t-1) {
        left += a[i] - b[i];
        c += abs(left);   
    } 

    left += a[t-1] - b[t-1];
    c += (ll)abs(left)*k;

    return c;
}

int main() {
    fastio;

    cin >> t >> k;
    a = vi (t);
    b = vi (t);
    forn(i, t) cin >> a[i];
    forn(i, t) cin >> b[i];

    int lo = -INF, hi = INF;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (cost(mid) > cost(mid+1)) lo = mid;
        else hi = mid;
    }

    cout << cost(hi) << endl; 

    return 0;
}
