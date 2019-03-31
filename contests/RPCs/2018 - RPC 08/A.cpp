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

const int MAXN = 2e3+10;
int a[MAXN], b[MAXN];

int main() {
    fastio;
    
    int n, m; 
    cin >> n >> m;

    forn(i, n) cin >> a[i];
    forn(i, m) cin >> b[i];

    map<int, int> ma;
    forn(i, n)
        forn(j, m)
            if (b[j] >= a[i])
                ma[b[j] - a[i]]++;

    int best = 0, mx = 0;
    for (pii p : ma) {
        int d = p.first, c = p.second;

        if (c > mx) {
            mx = c;
            best = d;
        }
    }

    cout << best << endl;

    return 0;
}
