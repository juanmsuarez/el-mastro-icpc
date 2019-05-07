#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long i64;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef vector<vi> vvi;
typedef vector<vi64> vvi64;
typedef double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int n;
  cin >> n;
  const int MAXN = (int) 1e6 + 10;
  vector<string> a(MAXN);
  vector<int> vv(n);
  for (int i = 0; i < n; i++) {
    string foo;
    cin >> foo;
    int v = 0;
    for (int j = 1; j < (int) foo.size(); j++) {
      v = v * 10 + (int) (foo[j] - '0');
    }
    vv[i] = v;
    if (foo[0] == 's') {
      a[v].push_back('(');
    } else {
      a[v].push_back(')');
    }
  }
  vector<vector<int>> good(MAXN);
  vector<int> pos(MAXN, 0);
  int cnt = 0;
  for (int type = 0; type < MAXN; type++) {
    if (a[type].empty()) {
      continue;
    }
    string& s = a[type];
    vector<int> balance(s.size() + 1);
    for (int i = 0; i < (int) s.size(); i++) {
      balance[i + 1] = balance[i] + (s[i] == '(' ? 1 : -1);
    }
    good[type].resize(s.size() + 1);
    if (balance.back() != 0) {
      continue;
    }
    int mn = *min_element(balance.begin(), balance.end());
    for (int i = 0; i < (int) balance.size(); i++) {
      good[type][i] = (balance[i] == mn);
    }
    cnt += good[type][0];
  }                  
  int best_cnt = cnt;
  int best_shift = 0;
  for (int shift = 0; shift < n; shift++) {
    if (cnt > best_cnt) {
      best_cnt = cnt;
      best_shift = shift;
    }
    int type = vv[shift];
    cnt -= good[type][pos[type]];
    pos[type]++;
    cnt += good[type][pos[type]];
  }
  cout << best_shift + 1 << " " << best_cnt << '\n';
  return 0;
}
