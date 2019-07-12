#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define snd second
using ll = long long;
using pii = pair<int, int>;

int main() {
    int n; cin >> n;
    cout << (n % 2 == 0 ? (n/2-1)/2 : 0) << endl;
}
