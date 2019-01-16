const int MAXP = 100100; // no inclusive
int criba[MAXP];
void crearcriba(){
	int w[] = {4, 2, 4, 2, 4, 6, 2, 6};
	for(int p = 25; p < MAXP; p += 10) criba[p] = 5;
	for(int p = 9; p < MAXP; p += 6) criba[p] = 3;
	for(int p = 4; p < MAXP; p += 2) criba[p] = 2;
	for(int p = 7, cur = 0; p*p < MAXP; p += w[cur++&7]) if(!criba[p]){
		for(int j = p*p; j < MAXP; j += (p << 1))
      if(!criba[j]) criba[j] = p;
	}
}
vector<int> primos;
void buscarprimos(){
	crearcriba();
	forsn(i, 2, MAXP) if(!criba[i]) primos.push_back(i);
}
//~ Useful for bit trick:
//~ #define SET(i) ( criba[(i)>>5]|=1<<((i)&31) )
//~ #define INDEX(i) ( (criba[i>>5]>>((i)&31))&1 )
//~ unsigned int criba[MAXP/32+1];
