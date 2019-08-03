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
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN = 1e5+10;
pii p[MAXN];

int main() {
    fastio;

    int n;
    cin >> n;

    int best = -1;
    forn(i, n) {
        cin >> p[i].first >> p[i].second;
        p[i].second = -p[i].second;
        if (best == -1 || p[i] < p[best])
            best = i;
    }

    bool can = true;
    forn(i, n) 
        if (!(p[i].first >= p[best].first && p[i].second >= p[best].second))
            can = false;

    cout << (can ? best+1 : -1) << endl;

    return 0;
}
