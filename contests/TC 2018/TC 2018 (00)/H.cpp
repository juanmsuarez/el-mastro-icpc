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

int main() {
    fastio;

    int n;
    cin >> n;

    map<pii, int> e;
    map<int, int> xs, ys;
    forn(i, n) {
        int x, y;
        cin >> x >> y;
        e[{x,y}]++;
        xs[x]++;
        ys[y]++;
    }

    ll rx = 0, ry = 0, req = 0;
    for (auto p : e) req += (ll)p.second*(p.second-1)/2;
    for (auto p : xs) rx += (ll)p.second*(p.second-1)/2;
    for (auto p : ys) ry += (ll)p.second*(p.second-1)/2;

    cout << rx + ry - req << endl;

    return 0;
}
