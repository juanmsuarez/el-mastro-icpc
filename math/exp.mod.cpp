int pot(int b, int e){ // O(log e). Puede hacer falta ll
	if(!e) return 1;
	int q = pot(b, e/2); q = mul(q, q);
	return (e % 2 ? mul(b, q) : q);
}
