const int N = 1e6;
int lp[N+1],p[N/5],sp=0; // prime_density(n) ~= n/ln(n)
// lp (least prime) allows fast factorization of numbers <= N

void sieve(){ // O(N)
	forsn(i,2,N+1){
		if(lp[i] == 0) lp[i] = i, p[sp++] = i;
		for(int j=0; j < sp && p[j] <= lp[i] && i*p[j] <= N; j++) lp[i*p[j]] = p[j]; 
	}
}

bool isPrime(int x){ // O(sqrt(x))
    if(x < 2 || !(x&1)) return 0;
    for(int i=3; i*i <= x; i += 2) 
        if(x % i == 0) return 0;
	return 1;
}
