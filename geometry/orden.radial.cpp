//orden total de puntos alrededor de un punto r
// hacer operadores ^ y - constantes
struct RadialOrder {
	pto r;
	RadialOrder(pto _r) : r(_r) {}
	int cuad(const pto &a) const {
		if(a.x > 0 && a.y >= 0) return 0;
		if(a.x <= 0 && a.y > 0) return 1;
		if(a.x < 0 && a.y <= 0) return 2;
		if(a.x >= 0 && a.y < 0) return 3;
		return -1;
	}
	bool comp(const pto &p1, const pto &p2) const {
		int c1 = cuad(p1), c2 = cuad(p2);
		if (c1 == c2) return (p1 ^ p2) > 0;
        else return c1 < c2;
	}
    bool operator()(const pto &p1, const pto &p2) const {
        return comp(p1 - r, p2 - r);
    }
};
