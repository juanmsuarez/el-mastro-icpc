/* Restricciones: Asume que las pendientes estan de mayor a menor
para calcular minimo o de menor a mayor para calcular maximo, sino
usar CHT online o Li-Chao Tree. Si puede haber pendientes iguales 
agregar if y dejar la que tiene menor (mayor) termino independiente
para minimo (maximo). Asume que los puntos a evaluar se encuentran
de menor a mayor, sino hacer bb en la chull y encontrar primera 
recta con Line.i >= x (lower_bound(x)). Si las rectas usan valores 
reales cambiar div por a/b y las comparaciones para que use EPS. 
Complejidad: Operaciones en O(1) amortizado. */
struct Line { ll a, b, i; };
struct CHT : vector<Line> {
    int p = 0; // pointer to lower_bound(x)
    ll div(ll a, ll b) { return a/b - ((a^b) < 0 && a % b); } // floor(a/b)
    void add(ll a, ll b) { // ax + b = 0
        while (size() > 1 && div(b - back().b, back().a - a) 
            <= at(size()-2).i) pop_back();
        if (!empty()) back().i = div(b - back().b, back().a - a);
        pb(Line{a, b, INF}); 
        if (p >= si(*this)) p = si(*this)-1;
    }
    ll eval(ll x) {
        while (at(p).i < x) p++;
        return at(p).a * x + at(p).b; 
    }
};
