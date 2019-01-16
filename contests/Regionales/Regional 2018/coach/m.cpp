#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans, last = -1;
    cin >> n; ans = n;
    while (n--) {
        int x; cin >> x;
        if (x <= last) ans--;
        last = x;
    }
    cout << ans << endl;
    return 0;
}
