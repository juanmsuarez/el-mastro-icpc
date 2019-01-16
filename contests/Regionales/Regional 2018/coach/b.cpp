#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];

    int j = 0, diam = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && (a[j] - a[i])*2 < a[n]) ++j;
        if (j < n && (a[j]-a[i])*2 == a[n]) ++diam;
    }
    cout << (diam >= 2 ? "Y" : "N") << endl;
    return 0;
}
