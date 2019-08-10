int cost(int l, int r); // Implementar

// Intervalos: cerrado, cerrado.
// Modificar tipos, comparador y neutro (INF). Revisar caso base (i, i+1).
const ll INF = 1e18;
ll knuth(int n) { 
    vector<vi> opt(n, vi(n));
    vector<vll> dp(n, vll(n));

    // Casos base
    forn(i, n-2) dp[i][i+2] = cost(i, i+2), opt[i][i+2] = i+1;

    // Casos recursivos
    forsn(len, 3, n+1) {
        forn(l, n-len) {
            int r = l+len;

            dp[l][r] = INF;
            forsn(k, opt[l][r-1], opt[l+1][r]+1) {
                ll val = dp[l][k] + dp[k][r] + cost(l, r);
                if (val < dp[l][r]) {
                    dp[l][r] = val;
                    opt[l][r] = k;
                }
            }
        }
    }

    return dp[0][n-1];
}
