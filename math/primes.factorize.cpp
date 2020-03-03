// Factorize numbers in log(x) with least prime of x (lp[x])
// P keeps primes until N and np the number of primes
// Check if it's prime in O(1) (lp[x] == x). 
const int N = 1e6;
int lp[N+1], p[N/5], np; // primeDensity(n) ~= n / ln(n)

void sieve() { // O(N)
	forsn(i, 2, N+1) {
		if (lp[i] == 0) lp[i] = i, p[np++] = i;
		for (int j = 0; j < np && p[j] <= lp[i] && i*p[j] <= N; j++) lp[i*p[j]] = p[j]; 
	}
}

void Eratosthenes(){ // O(n * log log n)
    forsn(i, 2, N+1) lp[i] = i;
    for (int i = 2; i*i <= N; i++) if (lp[i] == i) {
        for (int j = i*i; j <= N; j += i) if (lp[j] == j) lp[j] = i;
        P[np++] = i;
    }
}

bool isPrime(int x) { // O(sqrt(x))
    if (x < 2 || x % 2 == 0) return false;
    for (int i = 3; i*i <= x; i += 2) 
        if (x % i == 0) return false;
	return true;
}

map<ll,int> F;

void factorize(int x) { // O(log(x)), x <= N, sieve needed
    while (x > 1) F[lp[x]]++, x /= lp[x];
}

void factorize(ll x) { // O(sqrt(x)), sieve not needed 
    while (x % 2 == 0) F[2]++, x /= 2;
    for (ll i = 3; i*i <= x; i += 2) 
        while (x % i == 0) F[i]++, x /= i;
    if(x != 1) F[x]++;
}
