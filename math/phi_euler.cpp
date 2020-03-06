/* Euler's totient function (phi) counts the positive integers 
   up to a given integer n that are relatively prime to n.  */

const int N = 1e6;
vi lp(N+1), P, phi(N+1);

void initPhi() { // Least prime and phi <= N in O(n)
    phi[1] = 1;
    forsn(i, 2, N+1) {
        if (!lp[i]) 
            lp[i] = i, P.pb(i), phi[i] = i-1;
        else {
            int a = i / lp[i];
            phi[i] = phi[a] * (lp[i] - (lp[i] != lp[a]));
        }
        for (int p : P) {
            if (p > lp[i] || i*p > N) break;
            lp[i * p] = p;
        }
    }
}

ll eulerPhi(ll x) { // O(lg x)
    ll r = x;
    map<ll,int> f = fact(x);
    for (auto &i : f) r -= r / i.fst;
    return r;
}

ll eulerPhi(ll x) { // O(sqrt x)
    ll r = x;
    for (ll i = 2; i*i <= x; i++) {
        if (x % i == 0) {
            r -= r/i;
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) r -= r/x;
    return r;
}

/*

Calculation of phi:

0) phi(p) = p - 1 where p is prime
You can get it from the formula for PHI:
PHI [n] = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pn) where p1,p2.. pn are the prime factors of n.

Say we know the smallest prime factor of n, that is lp [n]. What is the formula for n/lp[n] ? Well there are two cases:

1) n/lp[n] is still divisible by lp[n], that is lp[n] is a factor of n with a power greater than or equal to 2, so n/lp[n] has exactly the same prime factors as n.
Then PHI[n/lp[n]] = (n/lp[n]) * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pn) It differs from the above formula by the first term. So just multiply phi[n/lp[n]] by lp[n] to get phi[n]. PHI[n] = PHI[n/lp[n]] * lp[n]

2) n/lp[n] is not divisible by lp[n], then the above formula for n/lp[n] is almost the same, it just doesn't have (1 — 1/lp[n]) as one of its terms. So we have to multiply phi[n/lp[n]] not only by lp[n] but also by (1 — 1/lp[n]).
Then PHI[n] = PHI[n/lp[n]] * lp[n] * (1 - 1/lp[n]) => PHI[n] = PHI[n/lp[n]] * (lp[n] - 1)
 
 */
