const int F = 1e6; 
int fact[F+1];
void factorials() {
    fact[0] = 1;
    forsn(i, 1, F+1) fact[i] = mul(i, fact[i-1]);
}

int permutations(int n, int k) {
    return divide(fact[n], fact[n-k]);
}

int combinations(int n, int k){
    return divide(fact[n], mul(fact[n-k], fact[k]));
}

const int MAXC = 1e3+1;
int C[MAXC][MAXC];
void combinations() {
    forn(i, MAXC) {
        C[i][0] = C[i][i] = 1;
        forsn(k, 1, i) C[i][k] = add(C[i-1][k], C[i-1][k-1]);
    }
}

// Stars and bars
int k_tuples_of_non_neg_int_whose_sum_is_n(int k, int n){ 
    return choose(n+k-1, n); 
}
int k_tuples_of_pos_int_whose_sum_is_n(int k, int n){ 
    return choose(n-1, k-1); 
}

const int MAXS = 1e3+1;
int S[MAXS][MAXS];
void stirling() {
	S[0][0] = 1;
	forsn(i, 1, N) S[i][0] = S[0][i] = 0;
	forsn(i, 1, N) forsn(j, 1, N) 
		S[i][j] = add(mul(S[i-1][j], j), S[i-1][j-1]);
}

const int MAXB = 1e3+1;
int B[MAXB][MAXB];
void bell() {
    B[0] = 1;
    forsn(i, 1, MAXB) forn(k, i)
        B[i] = add(B[i], mul(C[i-1][k], B[k]));
}

// Calcula C(n,k) % p teniendo C[p][p] precalculado, p primo
ll lucas(ll n, ll k, int p) { 
    ll ans = 1;
    while (n + k) { 
        ans = (ans * C[n % p][k % p]) % p; 
        n /= p, k /= p; 
    }
    return ans;
}
