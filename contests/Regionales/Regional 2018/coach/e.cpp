#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

typedef long long ll;
int n, x[N], y[N];

ll sign(int i, int j) {
    auto ni = (i+1)%n, nj = (j+1)%n;
    auto xi = x[ni] - x[i], yi = y[ni] - y[i];
    auto xj = x[nj] - x[j], yj = y[nj] - y[j];
    return ll(xi)*yj - ll(yi)*xj;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    ll ans = ll(n)*(n-1)*(n-2)/6;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (sign(i,j%n) >= 0) ++j;
        ll bad = j-i-1; ans -= bad*(bad-1)/2;
    }
    cout << ans << endl;
    return 0;
}
