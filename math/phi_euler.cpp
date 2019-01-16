const int N = 1e6;
int lp[N+1],P[N/5],phi[N+1],sp=0; // prime_density(n) ~= n/ln(n)
// lp (least prime) allows fast factorization of numbers <= N

// Euler's totient function (phi) counts the positive integers up to a given integer n that are relatively prime to n
void init_phi(){ // Primes and Phi <= N in O(N)
	phi[1] = 1;
	forsn(i,2,N+1){
		if(lp[i] == 0) lp[i] = i, P[sp++] = i, phi[i] = i-1;
		else phi[i] = lp[i] == lp[i/lp[i]] ? phi[i/lp[i]]*lp[i] : phi[i/lp[i]]*(lp[i]-1);
		for(int j = 0; j < sp && P[j] <= lp[i] && i*P[j] <= N; j++) lp[i*P[j]] = P[j];
	}
}

int eulerPhi(int n){ // O(sqrt(n)) (single number)
    int r = n;
    for(int i = 2; i*i <= n; i++) if(n % i == 0){
        r -= r/i;
        while(n % i == 0) n /= i;
    }
    if(n > 1) r -= r/n;
    return r;
}



/*

Explanation:
0) phi(p) = p - 1 where p is prime
You can get it from the formula for PHI:
PHI [n] = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pn) where p1,p2.. pn are the prime factors of n.
Say we know the smallest prime factor of n, that is lp [n]. What is the formula for n/lp[n] ? Well there are two cases:
1) n/lp[n] is still divisible by lp[n], that is lp[n] is a factor of n with a power greater than or equal to 2, so n/lp[n] has exactly the same prime factors as n.
Then PHI[n/lp[n]] = (n/lp[n]) * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pn) It differs from the above formula by the first term. So just multiply phi[n/lp[n]] by lp[n] to get phi[n]. PHI[n] = PHI[n/lp[n]] * lp[n]
2) n/lp[n] is not divisible by lp[n], then the above formula for n/lp[n] is almost the same, it just doesn't have (1 — 1/lp[n]) as one of its terms. So we have to multiply phi[n/lp[n]] not only by lp[n] but also by (1 — 1/lp[n]).
Then PHI[n] = PHI[n/lp[n]] * lp[n] * (1 - 1/lp[n]) => PHI[n] = PHI[n/lp[n]] * (lp[n] - 1)
 
 */
