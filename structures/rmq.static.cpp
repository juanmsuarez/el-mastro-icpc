// Dado un arreglo y una operacion asociativa idempotente:
// get(i, j) opera sobre el rango [i, j).
// Restriccion: LVL >= ceil(log n). Usar [ ] para llenar
// el arreglo y luego build().
struct RMQ {
    const static int LVL = 17;
	tipo vec[LVL][1 << (LVL + 1)];
	tipo &operator [](int p){ return vec[0][p]; }
	tipo get(int i, int j){ // intervalo [i, j)
		int p = 31 - __builtin_clz(j - i);
		return min(vec[p][i], vec[p][j - (1 << p)]);
	}
	void build(int n){ // O(n log n)
		int mp = 31 - __builtin_clz(n);
		forn(p, mp) forn(x, n - (1 << p))
      vec[p + 1][x] = min(vec[p][x], vec[p][x + (1 << p)]);
  }
};
