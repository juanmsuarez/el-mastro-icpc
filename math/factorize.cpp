map<ll,int> F;
const int N = 1e6;
int lp[N+1],P[N+1],sp=0; // prime_density(n) ~= n/ln(n)
// lp (least prime) allows fast factorization of numbers <= N

void sieve(){ // O(N)
	forsn(i,2,N+1){
		if(lp[i] == 0) lp[i] = i, P[sp++] = i;
		for(int j=0; j < sp && P[j] <= lp[i] && i*P[j] <= N; j++) lp[i*P[j]] = P[j]; 
	}
}

// TODO: No se puede hacer en O(logN) usando lp[n]?
void factorize(ll x){ // O(sqrt(x)), requires sieve (N > sqrt(x))
	for(ll n=x, i=0; x != 1 && ll(P[i])*P[i] <= n; i++)
		while(x % P[i] == 0) x /= P[i], F[P[i]]++; 
	if(x != 1) F[x]++;
}

// TODO: Factorizar O (sqrt(x)) sin criba
void factorize(ll x) { // O(sqrt(x)) 

}
