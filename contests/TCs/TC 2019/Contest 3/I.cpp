#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s, n) for (int i = (int)s; i < (int)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define snd second
#define si(a) ((int)(a).size())
#define pb emplace_back
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int n;
vi a;
vector<vi> memo;

int dp(int i, int j) {
    if (i == n) return 0;

    int &res = memo[i][j];
    if (res != -1) return res;

    if (a[j] > a[i]) j = i;
    res = dp(i+1, j) + 1;
    res = min(res, dp(i+1, i) + a[i] - a[j]);    

    return res;
}

int main() {
    cin >> n;
    a = vi(n); forn(i, n) cin >> a[i];    

    a.insert(a.begin(), 0); n++;
    memo = vector<vi>(n, vi(n, -1));
    cout << dp(1, 0) << endl;
    //upsolving

    return 0;
}
