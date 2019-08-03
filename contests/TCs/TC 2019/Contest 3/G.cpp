#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) a.begin(),a.end()
#define snd second
#define si(a) ((int)(a).size())
#define pb emplace_back
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ll n; cin >> n;

    ll ans = 0, k = 1;
    while (n > 1) {
        ans += n/2*k;
        n = (n + 1) / 2;
        k *= 2;
    }

    cout << ans << endl;
    //upsolving
}
