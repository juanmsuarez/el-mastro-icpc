// Modificar: tipos, operacion (max, min), neutro (INF), funcion de costo.
const ll INF = 1e18;

ll cost(int i, int j); // Implementar. Costo en rango [i, j).

vector<ll> dp_before, dp_cur;
// compute dp_cur[l, r)
void compute(int l, int r, int optl, int optr)
{
    if (l == r) return;
    int mid = (l + r) / 2;
    pair<ll, int> best = {INF, -1};

    forsn(k, optl, min(mid, optr)) 
        best = min(best, {dp_before[k] + cost(k, mid), k});

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid, optl, opt + 1);
    compute(mid + 1, r, opt, optr);
}

ll dc_opt(int n, int k) {
    dp_before.assign(n+1, INF); dp_before[0] = 0;
    dp_cur.resize(n+1); // Cuidado, dp_cur[0] = 0. No molesta porque no se elige.

    while (k--) {
        compute(1, n+1, 0, n); // Parametros tal que por lo menos 1 en cada subarreglo.
        dp_before = dp_cur;
    } 

    return dp_cur[n];
}
