map<ll,int> F;
const int N = 1e7;
int lp[N+1],P[N+1],sp=0; // prime_density(n) ~= n/ln(n)

void sieve(){ // O(N)
	forsn(i,2,N+1){
		if(lp[i] == 0) lp[i] = i, P[sp++] = i;
		for(int j=0; j < sp && P[j] <= lp[i] && i*P[j] <= N; j++) lp[i*P[j]] = P[j]; 
	}
}

void factorize(int x){ // O(log(x)), x <= N, sieve needed
    while(x != 1) F[lp[x]]++, x /= lp[x];
}

void factorize(ll x) { // O(sqrt(x)), no sieve needed 
    for(int i = 2; i*i <= x; i++) 
        while(x % i == 0) F[i]++, x /= i;
    if(x != 1) F[x]++;
}
