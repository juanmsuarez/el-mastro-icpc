struct RMQ2D { // n filas, m columnas
	int sz;
	RMQ t[4*MAXN]; // t[i][j] = i fila, j columna
	RMQ &operator [](int p){ return t[sz/2 + p]; }
	void init(int n, int m){ // O(n*m)
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz) t[i].init(m);
  }
	void set(int i, int j, tipo val){ // O(lg(m)*lg(n))
		for(i += sz; i > 0;){
			t[i].set(j, val);
			i /= 2;
			val = operacion(t[i*2][j], t[i*2 + 1][j]);
		} 
  }
	tipo get(int i1, int j1, int i2, int j2){
    return get(i1, j1, i2, j2, 1, 0, sz);
  }
	// O(lg(m)*lg(n)), rangos cerrado abierto
	int get(int i1, int j1, int i2, int j2, int n, int a, int b){
		if(i2 <= a || i1 >= b) return 0;
		if(i1 <= a && b <= i2) return t[n].get(j1, j2);
		int c = (a + b)/2;
		return operacion(get(i1, j1, i2, j2, 2*n, a, c),
                     get(i1, j1, i2, j2, 2*n + 1, c, b));
	}
} rmq;
// Ejemplo para inicializar una matriz de n filas por m columnas
RMQ2D rmq; rmq.init(n, m);
forn(i, n) forn(j, m){
	int v; cin >> v; rmq.set(i, j, v);
}
