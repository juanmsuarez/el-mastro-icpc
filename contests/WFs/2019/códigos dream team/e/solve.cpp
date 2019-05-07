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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef vector<vi> vvi;
typedef vector<vi64> vvi64;
typedef double ld;

const int maxn = 510000;
vi e[maxn];
int d[maxn], xr[maxn];

int mark[maxn], in_tree[maxn];

void dfs(int v, int p = -1) {
  in_tree[v] = 2;
  for (int u: e[v]) if (u != p) dfs(u, v);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;

  int n, m;
  cin >> n >> m;
  forn(i, m) {
    int v, u;
    cin >> v >> u;
    --v; --u;
    e[v].pb(u); e[u].pb(v);
    ++d[v]; ++d[u];
  }

  vi q;
  forn(i, n) if (d[i] == 1) q.pb(i);
  vi tree_rep;
  forn(cur, q.size()) {
    int v = q[cur];
    mark[v] = 1;
    bool any_unm = false;
    for (int u: e[v]) {
      if (mark[u]) continue;
      any_unm = true;
      --d[u];
      if (d[u] == 1) q.pb(u);
    }
    if (!any_unm) tree_rep.pb(v);
  }

  for (int v: tree_rep) dfs(v);

  vector<pii> ans;
  forn(v, n) for (int u: e[v]) {
    if (!mark[v] && mark[u] || in_tree[v] && e[v].size() == 1) ans.pb({v, u});
  }

  sort(all(ans));
  cout << ans.size() << '\n';
  for (auto w: ans) cout << w.fi + 1 << ' ' << w.se + 1 << '\n';

  return 0;
}
