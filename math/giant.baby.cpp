// Solves a^x = b (p) given a, b and p, or returns -1. O(sqrt(p)).
ll discrete_log(ll a, ll b, ll mod) {
  ll n = 0;
  ll a_n = 1;
  map<ll, int> babies;
  babies[b] = 0;
  for (n = 0; n * n <= mod; n++) {
    a_n = a_n * a % mod;
    b = b * a % mod;
    if (!babies.count(b)) babies[b] = n + 1;
  }
  ll cur = 1;
  for (int i = 1; i <= n; i++) {
    cur = cur * a_n % mod;
    if (babies.count(cur)) return n * i - babies[cur];
  }
  return -1;
}
