// Para 2D: tratar cada columna como un Fenwick Tree, 
// agregando un for anidado en cada operacion.
// Trucazo para 2D: si los elementos no se repiten,
// se puede usar un ordered set para memoria O(n*log^2(n))
typedef ll tipo;
struct Fenwick {
    static const int sz = (1 << 18) + 1;
    tipo t[sz];
    void adjust(int p, tipo v){ // p en [1, sz), O(lg n)
        for(int i = p; i < sz; i += (i & -i)) t[i] += v; 
    }
    tipo sum(int p){ // Suma acumulada en [1, p], O(lg n)
        tipo s = 0;
        for(int i = p; i; i -= (i & -i)) s += t[i];
        return s;
    }
    tipo sum(int a, int b){ return sum(b) - sum(a - 1); }
    int lower_bound(tipo v) { // Menor x con suma acumulada >= v, O(lg n)
        int x = 0, d = sz-1;
        if(v > t[d]) return sz;
        for(; d; d >>= 1) 
            if(t[x|d] < v) v -= t[x |= d];
        return x+1; 
    }
};
