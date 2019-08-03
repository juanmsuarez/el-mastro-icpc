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
    #define D(a) //cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN = 3e5+10;
int t[MAXN], finalt[MAXN];
double p[MAXN];

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    forn(i, n) cin >> t[i] >> p[i];

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int k = min(n, m);
    forn(i, k) pq.push({t[i], i});

    double e = 0;
    while (!pq.empty()) {
        int tiempo = pq.top().first, i = pq.top().second;
        pq.pop();

        finalt[i] = tiempo;

        if (k < n) {
            pq.push({tiempo + t[k], k});
            k++;
        }
    }

    int mx = 0;
    double prob = 1;
    forn(i, n) {
        mx = max(mx, finalt[i]);

        e += prob*(1-p[i])*mx;

        prob *= p[i];
    }
    e += prob*mx;

    cout << fixed << setprecision(5) << e << endl;

    return 0;
}
