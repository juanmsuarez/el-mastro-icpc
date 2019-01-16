#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n; cin >> n;
    vector<int> d(n), c(n), dp(n+1);
    for (int i = 0; i < n; i++) cin >> d[i] >> c[i];
    vector<int> k = {4,2,1,1,1,1};
    for (int from = n-1; from >= 0; --from) {
        int duration = 0, cost = 0;
        dp[from] = INF;
        for (int to = from; to < n && to-from < 6 && duration < 120; ++to) {
            cost += k[to-from] * c[to];
            dp[from] = min(dp[from], cost + dp[to+1]);
            duration += d[to];
        }
    }
    cout << fixed << setprecision(2) << dp[0] / 4.0 << endl;
    return 0;
}
