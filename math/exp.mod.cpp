ll pot(ll b, ll e){ // O(log e)
	ll r=1;
    while (e) {
        if (e&1) r *= b; 
        e >>= 1; b *= b;
    }
    return r;
}
