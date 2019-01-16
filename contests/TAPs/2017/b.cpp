#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i = 0; i <(int)(n); i++)
#define forsn(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define dforsn(i,s,n) for (int i = (int)(n-1); i >= (int)(s); i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define si(v) ((int)v.size())

typedef vector<int> vi;
typedef long long int tint;

const int MAXN = 1e5+10, MOD = 1e9+7;
int p[MAXN], c[MAXN];

int main() {
    int n;
    cin >> n;

    forn(i, n) cin >> p[i];
    forn(i, n) cin >> c[i];

    sort(p, p+n);
    sort(c, c+n);

    int ind = n-1;
    tint ans = 1;
    dforsn(i, 0, n) {
        while (ind > 0 && c[ind-1] >= p[i]) ind--;
        ans = (ans * (n - ind - (n-1-i))) % MOD;
    }
    cout << ans << endl;

    return 0;
}
