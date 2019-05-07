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

const int inf = (int) 1e9;

vector<int> xa, ya, xb, yb;
vector<long long> A, B, C;

struct Comp {
  bool operator ()(int i, int j) {
    int xl = max(min(xa[i], xb[i]), min(xa[j], xb[j]));
    int xr = min(max(xa[i], xb[i]), max(xa[j], xb[j]));
    assert(xl <= xr);
    long long num_i = -A[i] * xl - C[i];
    long long den_i = B[i];
    long long num_j = -A[j] * xl - C[j];
    long long den_j = B[j];
    if (num_i % den_i == 0) {
      num_i /= den_i;
      den_i = 1;
    }
    if (num_j % den_j == 0) {
      num_j /= den_j;
      den_j = 1;
    }
    if (den_i < 0) {
      num_i = -num_i;
      den_i = -den_i;
    }
    if (den_j < 0) {
      num_j = -num_j;
      den_j = -den_j;
    }
    return num_i * den_j < num_j * den_i;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int l_seg, r_seg, n;
  cin >> l_seg >> r_seg >> n;
  l_seg *= 2;
  r_seg *= 2;
  xa.resize(n);
  ya.resize(n);
  xb.resize(n);
  yb.resize(n);
  A.resize(n);
  B.resize(n);
  C.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
    xa[i] *= 2;
    xb[i] *= 2;
    A[i] = yb[i] - ya[i];
    B[i] = xa[i] - xb[i];
    C[i] = -A[i] * xa[i] - B[i] * ya[i];
  }
  vector<pair<int, int>> e;
  for (int i = 0; i < n; i++) {
    e.emplace_back(min(xa[i], xb[i]), i);
    e.emplace_back(max(xa[i], xb[i]) + 1, ~i);
  }
  sort(e.begin(), e.end());
  vector<vector<int>> graph(n);
  set<int, Comp> s;
  for (auto& p : e) {
    int id = p.second;
    if (id >= 0) {
      s.insert(id);
      auto it = s.find(id);
      if (it != s.begin()) {
        graph[*prev(it)].push_back(*it);
      }
      auto jt = next(it);
      if (jt != s.end()) {
        graph[*it].push_back(*jt);
      }
    } else {
      id = ~id;
      auto it = s.find(id);
      if (it != s.begin() && it != s.end()) {
        auto jt = next(it);
        if (jt != s.end()) {
          graph[*prev(it)].push_back(*jt);
        }
      }
      s.erase(it);
    }
//    cerr << "s:";
//    for (int j : s) cerr << " " << j;
//    cerr << '\n';
  }
/*  for (int i = 0; i < n; i++) {
    cerr << i << ":";
    for (int j : graph[i]) {
      cerr << " " << j;
    }
    cerr << '\n';
  }*/
  vector<int> in_deg(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j : graph[i]) {
      in_deg[j]++;
    }
  }
  vector<int> que;
  for (int i = 0; i < n; i++) {
    if (in_deg[i] == 0) {
      que.push_back(i);
    }
  }
  for (int b = 0; b < (int) que.size(); b++) {
//    cerr << " " << que[b];
    for (int j : graph[que[b]]) {
      if (--in_deg[j] == 0) {
        que.push_back(j);
      }
    }
  }
  assert((int) que.size() == n);
  map<int, int> pos;
  map<int, int> neg;
  auto Modify = [&](int v, int delta) {
    if (delta == 0) {
      return;
    }
    auto it = pos.find(v);
    if (it != pos.end()) {
      int val = it->second;
      if (val + delta > 0) {
        it->second += delta;
      } else {
        pos.erase(it);
        if (val + delta < 0) {
          neg[v] = val + delta;
        }
      }
      return;
    }
    it = neg.find(v);
    if (it != neg.end()) {
      int val = it->second;
      if (val + delta < 0) {
        it->second += delta;
      } else {
        neg.erase(it);
        if (val + delta > 0) {
          pos[v] = val + delta;
        }
      }
      return;
    }
    if (delta > 0) {
      pos[v] = delta;
    } else {
      neg[v] = delta;
    }
  };
  Modify(l_seg, -inf);
  Modify(r_seg + 1, inf);
/*  for (auto& p : pos) {
    cerr << "{" << p.first << " " << p.second << "} ";
  }
  for (auto& p : neg) {
    cerr << "{" << p.first << " " << p.second << "} ";
  }
  cerr << "\n";*/
  for (int id : que) {
    if (xa[id] < xb[id]) {
      Modify(xa[id] + 1, 1);
      Modify(xb[id] + 1, -1);
      while (true) {
        auto it = pos.lower_bound(xa[id] + 1);
        if (it == pos.end() || it->first > xb[id]) {
          break;
        }
        auto p = *it;
        auto jt_pos = pos.lower_bound(p.first + 1);
        auto jt_neg = neg.lower_bound(p.first + 1);
        int j = xb[id] + 1;
        if (jt_pos != pos.end()) {
          j = min(j, jt_pos->first);
        }
        if (jt_neg != neg.end()) {
          j = min(j, jt_neg->first);
        }
        Modify(p.first, -p.second);
        Modify(j, p.second);
      }
    } else {
      Modify(xa[id], -1);
      Modify(xb[id], 1);
      while (true) {
        auto it = neg.lower_bound(xa[id] + 1);
        if (it == neg.begin() || prev(it)->first <= xb[id]) {
          break;
        }
        auto p = *prev(it);
//        cerr << "p: " << p.first << " " << p.second << " (" << xb[id] << ")" << '\n';
        auto jt_pos = pos.lower_bound(p.first);
        auto jt_neg = neg.lower_bound(p.first);
        int j = xb[id];
        if (jt_pos != pos.begin()) {
          j = max(j, prev(jt_pos)->first);
        }
        if (jt_neg != neg.begin()) {
          j = max(j, prev(jt_neg)->first);
        }
//        cerr << "j = " << j << '\n';
        Modify(p.first, -p.second);
        Modify(j, p.second);
      }
    }
/*    for (auto& p : pos) {
      cerr << "{" << p.first << " " << p.second << "} ";
    }
    for (auto& p : neg) {
      cerr << "{" << p.first << " " << p.second << "} ";
    }
    cerr << "\n";*/
  }
  map<int, int> mp;
  mp[l_seg] = 0;
  for (auto& p : pos) {
    mp[p.first] = p.second;
  }
  for (auto& p : neg) {
    mp[p.first] = p.second;
  }
  int ans = inf;
  int balance = 0;
  for (auto& p : mp) {
    balance += p.second;
    if (p.first >= l_seg && p.first <= r_seg) {
      ans = min(ans, balance);
    }
  }
  cout << ans + inf << '\n';
  return 0;
}
