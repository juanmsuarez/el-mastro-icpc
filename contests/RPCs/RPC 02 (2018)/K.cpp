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

const int MAXN = 1e5+10;
int n, c[MAXN];

bool can(int m, vi cant, vi val) {
    forn(i, n) {
        int mn = 0, bestJ, bestK;
        forn(j, 3) forn(k, 3) {
            if (cant[j] == 0 || cant[k] == 0 || (j == k && cant[j] == 1)) continue;

            int sum = val[j] + val[k];
            if (sum*c[i] >= m) {
                if (mn == 0 || sum < mn) {
                    mn = sum;
                    bestJ = j;
                    bestK = k;
                }
            }
        }

        if (mn == 0) return false;
        else cant[bestJ]--, cant[bestK]--;
    }
    return true;
}

int main() {
    fastio;

    n = 0;
    vi cant(3), val(3);
    forn(i, 3) {
        cin >> cant[i];
        n += cant[i];
    }
    n /= 2;
    forn(i, 3) cin >> val[i];
    forn(i, n) cin >> c[i];

    int lo = 2, hi = 2*1e3*1e5+1;
    while (hi - lo > 1) {
        int mid = (lo+hi)/2;
        if (can(mid, cant, val)) {
            lo = mid;
        }
        else {
            hi = mid;
        }
    }

    cout << lo << endl;

    return 0;
}
