const int MAXM = 15485867; // Tiene que ser primo
ll inv[MAXM]; //inv[i]*i=1 M M
void calc(int p){//O(p)
	inv[1]=1;
	forsn(i, 2, p) inv[i]= p-((p/i)*inv[p%i])%p;
}
// Llamar calc(MAXM);

int inv(int x){//O(log x)
	return pot(x, eulerphi(M)-1);//si M no es primo(sacar a mano)
	return pot(x, M-2);//si M es primo
}

// Inversos con euclides en O(log(x)) sin precómputo:
// extendedEuclid(a, -m).fst (si coprimos a y m)
