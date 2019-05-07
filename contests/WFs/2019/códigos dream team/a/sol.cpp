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
  vector<int> b_h(n), b_p(n);
  vector<int> f_h(n), f_p(n);
  for (int i = 0; i < n; i++) {
    cin >> b_p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b_h[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> f_p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> f_h[i];
  }
  vector<int> b_order(n), f_order(n);
  iota(b_order.begin(), b_order.end(), 0);
  iota(f_order.begin(), f_order.end(), 0);
  sort(b_order.begin(), b_order.end(), [&](int i, int j) { return b_p[i] < b_p[j]; });
  sort(f_order.begin(), f_order.end(), [&](int i, int j) { return f_p[i] < f_p[j]; });
  int b_i = 0;
  int f_i = 0;
  set<pair<int, int>> b_s, f_s;
  vector<int> b_ans(n), f_ans(n);
  for (int iter = 0; iter < n; iter++) {
    if (b_s.empty()) {
      while (b_i < n) {
        b_s.emplace(b_h[b_order[b_i]], b_order[b_i]);
        b_i++;
        if (b_i == n || b_p[b_order[b_i - 1]] != b_p[b_order[b_i]]) {
          break;
        }
      }
    }
    if (f_s.empty()) {
      while (f_i < n) {
        f_s.emplace(f_h[f_order[f_i]], f_order[f_i]);
        f_i++;
        if (f_i == n || f_p[f_order[f_i - 1]] != f_p[f_order[f_i]]) {
          break;
        }
      }
    }
/*    for (auto& p : b_s) cerr << "{" << p.first << " " << p.second << "} ";
    cerr << '\n';
    for (auto& p : f_s) cerr << "{" << p.first << " " << p.second << "} ";
    cerr << '\n';*/
    if (b_s.size() < f_s.size()) {
      int i = b_s.begin()->second;
      b_s.erase(b_s.begin());
      b_ans[iter] = i;
      auto it = f_s.lower_bound(make_pair(b_h[i], -1));
      if (it == f_s.begin()) {
        cout << "impossible" << '\n';
        return 0;
      }
      it = prev(it);
      f_ans[iter] = it->second;
      f_s.erase(it);
    } else {
      int i = f_s.begin()->second;
      f_s.erase(f_s.begin());
      f_ans[iter] = i;
      auto it = b_s.lower_bound(make_pair(f_h[i] + 1, -1));
      if (it == b_s.end()) {
        cout << "impossible" << '\n';
        return 0;
      }
      b_ans[iter] = it->second;
      b_s.erase(it);
    }
//    cerr << "pair: " << b_ans[iter] << " " << f_ans[iter] << '\n';
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << b_ans[i] + 1;
  }
  cout << '\n';
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << f_ans[i] + 1;
  }
  cout << '\n';
  return 0;
}
