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

const long long inf = (long long) 2e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int p, h;
  cin >> p >> h;
  vector<vector<int>> a(p, vector<int>(h));
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < h; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<pair<long long, int>>> events(p);
  for (int me = 0; me < p; me++) {
    for (int him = 0; him < p; him++) {
      if (me == him) {
        continue;
      }
      vector<pair<int, int>> e(1, make_pair(1, 0));
      for (int i = 0; i < h; i++) {
        e.emplace_back(a[me][i], 1);
      }
      for (int i = 0; i < h; i++) {
        e.emplace_back(a[him][i], -1);
      }
      sort(e.begin(), e.end());
      long long sum_me = 0;
      int cnt_me = h;
      long long sum_him = 0;
      int cnt_him = h;
      int beg = 0;
      while (beg < (int) e.size()) {
        int end = beg;
        while (end + 1 < (int) e.size() && e[end + 1].first == e[end].first) {
          end++;
        }
        for (int i = beg; i <= end; i++) {
          if (e[i].second == 1) {
            sum_me += e[i].first;
            cnt_me--;
          }
          if (e[i].second == -1) {
            sum_him += e[i].first;
            cnt_him--;
          }
        }
        long long from = e[beg].first;
        long long to = (end == (int) e.size() - 1 ? inf : e[end + 1].first - 1);
//        cerr << me << " " << him << " " << from << " " << to << '\n';
//        cerr << from << " " << to << " " << sum_me << " " << cnt_me << " " << sum_him << " " << cnt_him << '\n';
        // sum_me + cnt_me * t < sum_him + cnt_him * t?
        long long k = cnt_him - cnt_me;
        long long b = sum_him - sum_me;
        long long period = to - from + 1;
        b += from * k;
        // t = [0..period)
        // b + k * t > 0?
        if (k == 0) {
          if (b > 0) {
            events[me].emplace_back(from, -1);
            events[me].emplace_back(to + 1, 1);
          }
        } else {
          if (k < 0) {
            if (b > 0) {
              long long steps = (b - 1) / (-k);
              events[me].emplace_back(from, -1);
              events[me].emplace_back(from + min(period, steps + 1), 1);
            }
          } else {
            // k > 0
            if (b > 0) {
              events[me].emplace_back(from, -1);
              events[me].emplace_back(to + 1, 1);
            } else {
              long long t = (-b) / k + 1;
              if (t <= period) {
//                assert(from + t <= to);
//                assert(t >= 0);
                events[me].emplace_back(from + t, -1);
                events[me].emplace_back(to + 1, 1);
              }
            }
          }
        }
        beg = end + 1;
      }
    }
  }
  for (int i = 0; i < p; i++) {
    sort(events[i].begin(), events[i].end());
    int best = p;
    int cur = p;
    int beg = 0;
    while (beg < (int) events[i].size()) {
      int end = beg;
      while (end + 1 < (int) events[i].size() && events[i][end + 1].first == events[i][end].first) {
        end++;
      }
      for (int j = beg; j <= end; j++) {
        cur += events[i][j].second;
      }
      best = min(best, cur);
      beg = end + 1;
    }
    cout << best << '\n';
  }
  return 0;
}
