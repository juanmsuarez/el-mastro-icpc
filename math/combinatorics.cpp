int MAXS = 1e3+1, S[MAXS][MAXS];
void stirling(){
	S[0][0] = 1;
	forsn(i,1,N) S[i][0] = S[0][i] = 0;
	forsn(i,1,N) forsn(j,1,N) 
		S[i][j] = add(mul(S[i-1][j],j),S[i-1][j-1]);
}

int MAXC = 1e3+1, C[MAXC][MAXC];
forn(i,MAXC){ // C[n][k] = C(n, k)
    C[i][0] = C[i][i] = 1;
    forsn(k,1,i) C[i][k] = add(C[i-1][k],C[i-1][k-1]);
}

int bell[MAXC+1][MAXC+1];
ll bell(int n){
    bell[0] = 1;
    forsn(i,1,n+1) forsn(k,0,i)
        bell[i] = add(bell[i],mul(C[i-1][k],bell[k]));
}

ll lucas(ll n, ll k, int p){ // Calcula C(n,k) % p teniendo C[p][p] precalculado, p primo
    ll ans = 1;
    while(n + k){ ans = (ans * C[n%p][k%p]) % p; n/=p; k/=p; }
    return ans;
}

int F = 1e6, fact[F+1];
fact[0] = 1;
forsn(i,1,F+1) fact[i] = mul(i, fact[i-1]);

int choose(int n, int c){
    return divide(fact[n], mul(fact[n-c], fact[c]));
}

int k_tuples_of_non_neg_int_whose_sum_is_n(int k, int n){ 
    return choose(n+k-1, n); 
}
int k_tuples_of_pos_int_whose_sum_is_n(int k, int n){ 
    return choose(n-1, k-1); 
}
