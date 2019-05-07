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

const int maxn = 1001;
int x[maxn], r[maxn], g[maxn];

int gcd(int x, int y) {
  while (y) {
    x %= y;
    swap(x, y);
  }
  return x;
}

bool isPrime(int x) {
  for (int p = 2; p * p <= x; ++p) if (x % p == 0) return false;
  return true;
}

double prob[maxn];
const int maxa = 101;
typedef bitset<maxa> bs;
bs subset[maxa][maxa][maxa];

int mod(int x, int y) {
  x %= y;
  if (x < 0) x += y;
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;

  int M = 32 * 27 * 5 * 7;

  vi ps;
  fore(p, 2, 100) if (isPrime(p)) ps.pb(p);
  vi en(100);
  forn(i, ps.size()) en[ps[i]] = i;

  for1(L, 100) {
    int z = L / gcd(L, M);
    if (z == 1) continue;
    forn(rc, L + 1) forn(m, L) forn(k, z) {
      int zz = k * M + m;
      if (mod(zz, L) >= rc) subset[L][rc][m][k] = 1;
    } 
  }

  int n;
  cin >> n;
  forn(i, n) cin >> x[i] >> r[i] >> g[i];

  forn(R, M) {
    vector<bs> good(ps.size());
    forn(i, ps.size()) forn(j, ps[i]) good[i][j] = 1;
    double P = 1.0;
    forn(i, n + 1) {
      prob[i] += P;
      if (i == n || P < 1e-15) break;
      int L = r[i] + g[i];
      int z = L / gcd(L, M);
      if (z == 1) {
        if (mod(R + x[i], L) < r[i]) break;
      } else {
        int id = en[z];
        P /= good[id].count();
//        cerr << L << ' ' << r[i] << ' ' << mod(R + x[i], z) <<'\n';
        good[id] = good[id] & subset[L][r[i]][mod(R + x[i], L)];
        P *= good[id].count();
/*        forn(k, z) {
          int zz = k * M + R;
          if (mod(zz + x[i], L) < r[i] && good[id][k]) {
            good[id][k] = 0;
            P /= sum[id];
            --sum[id];
            P *= sum[id];
          }
        }*/
      }
    }
  }

  forn(i, n + 1) cout << (prob[i] - prob[i + 1]) / M << '\n';

  return 0;
}
