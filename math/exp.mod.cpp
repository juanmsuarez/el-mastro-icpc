ll pot(ll b, ll e){ // O(log e)
	if(!e) return 1;
	ll q = pot(b, e/2); q = mul(q, q);
	return (e & 1 ? mul(b, q) : q);
}
