#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define alll(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long i64;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef vector<vi> vvi;
typedef vector<vi64> vvi64;
typedef double ld;

const int MAXN = (int) 1e6 + 10;
const int LOG = 21;
const int ALPHA = 26;

int pr[MAXN][LOG];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int n, tt;
  cin >> n >> tt;
  n++;
  vector<int> pv(n);
  vector<int> pc(n);
  for (int i = 1; i < n; i++) {
    char foo;
    cin >> foo >> pv[i];
    pc[i] = (int) (foo - 'A');
  }
  pc[0] = -1;
  pv[0] = -1;
  for (int i = 0; i < n; i++) {
    pr[i][0] = pv[i];
  }
  for (int j = 1; j < LOG; j++) {
    for (int i = 0; i < n; i++) {
      if (pr[i][j - 1] == -1) {
        pr[i][j] = -1;
      } else {
        pr[i][j] = pr[pr[i][j - 1]][j - 1];
      }
    }
  }
  vector<int> sa(1, 0);
  vector<vector<int>> all(ALPHA);
  for (int i = 1; i < n; i++) {
    all[pc[i]].push_back(i);
  }
  vector<int> group(n);
  sa.reserve(n);
  group[0] = -1;
  for (int i = 0; i < ALPHA; i++) {
    for (int j : all[i]) {
      group[sa.size()] = i;
      sa.push_back(j);
    }
  }
  vector<int> pos(n);
  vector<int> new_sa(n);
  vector<int> new_group(n);
  for (int step = 0; step < LOG; step++) {
//    cerr << "sa:";
//    for (int i = 0; i < n; i++) {
//      cerr << " " << sa[i];
//    }
//    cerr << '\n';
    for (int i = 0; i < n; i++) {
      pos[sa[i]] = i;
    }
    int beg = 0;
    int cntg = 0;
    int nn = 0;
    while (beg < n) {
      int end = beg;
      while (end + 1 < n && group[end + 1] == group[end]) {
        end++;
      }
      vector<pair<int, int>> t(end - beg + 1);
      for (int i = beg; i <= end; i++) {
        int p = pr[sa[i]][step];
        t[i - beg] = make_pair(p == -1 ? -1 : group[pos[p]], sa[i]);
      }
      sort(t.begin(), t.end());
      for (int i = 0; i <= end - beg; i++) {
        new_sa[nn] = t[i].second;
        if (i > 0 && t[i].first != t[i - 1].first) {
          cntg++;
        }
        new_group[nn] = cntg;
        nn++;
      }
      cntg++;
      beg = end + 1;
    }
    swap(sa, new_sa);
    swap(group, new_group);
    if (cntg == n) {
      break;
    }
  }
  auto Get = [&](int i, int j) {
    for (int k = LOG - 1; k >= 0; k--) {
      if (j & (1 << k)) {
        i = pr[i][k];
        if (i == -1) {
          return -1;
        }
      }
    }
    return pc[i];
  };
  while (tt--) {
    string s;
    cin >> s;
    int from = 0, to = n - 1;
    for (int i = 0; i < (int) s.size(); i++) {
      int c = (int) (s[i] - 'A');
      int low = from, high = to + 1;
      while (low < high) {
        int mid = (low + high) >> 1;
        if (Get(sa[mid], i) < c) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
      from = low;
      low = from - 1, high = to;
      while (low < high) {
        int mid = (low + high + 1) >> 1;
        if (Get(sa[mid], i) > c) {
          high = mid - 1;
        } else {
          low = mid;
        }
      }
      to = low;
//      cerr << i << " -> " << from << " " << to << '\n';
      if (from > to) {
        break;
      }
    }
    cout << to - from + 1 << '\n';
  }
  return 0;
}
