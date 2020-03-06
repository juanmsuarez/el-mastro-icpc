// P keeps primes until N. Check if a number is prime with lp[x] == x.
const int N = 1e6;
vi lp(N+1), P;

void sieve() { // O(n)
	forsn(i, 2, N+1) {
		if (!lp[i]) lp[i] = i, P.pb(i);
        for (int p : P) {
            if (p > lp[i] || i*p > N) break;
            lp[i * p] = p;
        }
	}
}

void eratosthenes() { // O(n * log log n)
    forsn(i, 2, N+1) lp[i] = i & 1 ? i : 2;
    for (int i = 3; i*i <= N; i += 2) if (lp[i] == i) {
        for (int j = i*i; j <= N; j += 2*i) if (lp[j] == j) lp[j] = i;
        P.pb(i);
    }
}

bool prime(int x) { // O(sqrt x)
    if (x < 2 || x % 2 == 0) return false;
    for (int i = 3; i*i <= x; i += 2) 
        if (x % i == 0) return false;
	return true;
}
