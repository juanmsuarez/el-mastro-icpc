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

    ll n, k;
    cin >> n >> k;

    vector<ll> ds;
    for (ll i = 1; i*i <= n; i++)
        if (n%i == 0) {
            ds.pb(i);
            if (i*i != n)
                ds.pb(n/i);
        }

    ll mx = -1;
    for (ll d : ds) {
        ll suma = n / d;

        // k * k no entra en ll
        if (k <= (ll)1e9 && k*(k+1)/2 <= suma) 
            mx = max(mx, d);
    }

    if (mx == -1) cout << -1 << endl;
    else {
        ll suma = n/mx;

        forsn(i, 1, k) cout << mx*i << ' ';
        suma -= (k-1)*k/2;
        cout << mx*suma << endl;
    }

    return 0;
}
