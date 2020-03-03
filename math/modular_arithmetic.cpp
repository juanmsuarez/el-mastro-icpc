const int M = 1e9 + 7;
int add(int a, int b){ return a+b < M ? a+b : a+b-M; }
int sub(int a, int b){ return a-b >= 0 ? a-b : a-b+M; }
int mul(int a, int b){ return int(ll(a)*b % M); }
int pot(int b, int e){ // O(log e)
	if(!e) return 1;
	int q = pot(b,e/2); q = mul(q, q);
	return (e & 1 ? mul(b, q) : q);
}
int inv(int x){ return pot(x, M-2); } // Change M-2 for Phi(M)-1 if M isn't prime
int divide(int a, int b) { return mul(a, inv(b)); }
int neg(int a){ return add(-a, M); }
int normal(int a){ return ((a % M) + M) % M;} // For neg numbers
