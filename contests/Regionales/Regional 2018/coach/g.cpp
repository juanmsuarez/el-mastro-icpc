#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
typedef long long ll;
typedef pair<int,int> pii;

const int N = 1010;
const int MOD = 1e9 + 7;

int n, x[N], y[N], comb[N][N];

struct val {
    int ind, pre, sz;
} dsu[N];

vector<val> hist;

int find(int x) { return dsu[x].pre == x  ? x : find(dsu[x].pre); }

int merge(int x, int y) {
    auto a = find(x), b = find(y);
    if (a == b) return 1;

    auto ans = comb[dsu[a].sz][dsu[b].sz];
    if (dsu[a].sz < dsu[b].sz) swap(a,b);

    hist.emplace_back(dsu[b]);
    dsu[b].pre = a;

    hist.emplace_back(dsu[a]);
    dsu[a].sz += dsu[b].sz;
    return ans;
}

void restore(size_t top) {
    while (hist.size() > top) {
        auto ind = hist.back().ind;
        dsu[ind] = hist.back();
        hist.pop_back();
    }
}

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    cin >> n;
    forn(i,n) cin >> x[i] >> y[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) comb[i][j] = 1;
            else {
                comb[i][j] = comb[i-1][j];
                add(comb[i][j], comb[i][j-1]);
            }
        }
    }

    map<pii, vector<pii>> evt;
    vector<pii> eq;
    forn(j,n) forn(i,j) {
        auto nx = y[j] - y[i], ny = x[i] - x[j];
        if (nx && ny && ((nx > 0) == (ny > 0))) {
            nx = abs(nx); ny = abs(ny);
            auto d = __gcd(nx,ny);
            nx /= d; ny /= d;
            evt[make_pair(nx,ny)].emplace_back(i,j);
        }
        else if (nx == 0 && ny == 0) eq.emplace_back(i,j);
    }
    forn(u,n) dsu[u] = {u,u,1};

    ll ways = 1;
    for (auto uv : eq) {
        int u,v; tie(u,v) = uv;
        ways = ways * merge(u,v) % MOD;
    }
    
    ll ans = 1;
    for (auto &kv : evt) {
        auto sz = hist.size();
        auto &edges = kv.second;
        ll mult = 1;
        for (auto uv : edges) {
            int u,v; tie(u,v) = uv;
            mult = mult * merge(u,v) % MOD;
        }
        ans += mult+MOD-1;

        restore(sz);
    }
    cout << ans%MOD * ways % MOD << endl;

    return 0;
}
