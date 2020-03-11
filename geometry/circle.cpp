vec perp(vec v){return vec(-v.y, v.x);}
line bisector(pto x, pto y){
	line l=line(x, y); pto m=(x+y)/2;
	return line(-l.b, l.a, -l.b*m.x+l.a*m.y);
}
struct Circle{
	pto o;
	double r;
	Circle(pto x, pto y, pto z){
		o=inter(bisector(x, y), bisector(y, z));
		r=dist(o, x);
	}
	pair<pto, pto> ptosTang(pto p){
		pto m=(p+o)/2;
		tipo d=dist(o, m);
		tipo a=r*r/(2*d);
		tipo h=sqrt(r*r-a*a);
		pto m2=o+(m-o)*a/d;
		vec per=perp(m-o)/d;
		return make_pair(m2-per*h, m2+per*h);
	}
};
//finds the center of the circle containing p1 and p2 with radius r
//as there may be two solutions swap p1, p2 to get the other
bool circle2PtsRad(pto p1, pto p2, double r, pto &c){
        double d2=(p1-p2).norm2(), det=r*r/d2-0.25;
        if(det<0) return false;
        c=(p1+p2)/2+perp(p2-p1)*sqrt(det);
        return true;
}
#define sqr(a) ((a)*(a))
#define feq(a,b) (fabs((a)-(b))<EPS)
pair<tipo, tipo> ecCuad(tipo a, tipo b, tipo c){//a*x*x+b*x+c=0
	tipo dx = sqrt(b*b-4.0*a*c);
	return make_pair((-b + dx)/(2.0*a),(-b - dx)/(2.0*a));
}
pair<pto, pto> interCL(Circle c, line l){
	bool sw=false;
	if((sw=feq(0,l.b))){
	swap(l.a, l.b);
	swap(c.o.x, c.o.y);
	}
	pair<tipo, tipo> rc = ecCuad(
	sqr(l.a)+sqr(l.b),
	2.0*l.a*l.b*c.o.y-2.0*(sqr(l.b)*c.o.x+l.c*l.a),
	sqr(l.b)*(sqr(c.o.x)+sqr(c.o.y)-sqr(c.r))+sqr(l.c)-2.0*l.c*l.b*c.o.y
	);
	pair<pto, pto> p( pto(rc.first, (l.c - l.a * rc.first) / l.b),
					  pto(rc.second, (l.c - l.a * rc.second) / l.b) );
	if(sw){
	swap(p.first.x, p.first.y);
	swap(p.second.x, p.second.y);
	}
	return p;
}

------------------------------------------------------------------

struct circle { 
    pto p; double r; 
    bool contains(pto a) { return leq(dist(p, a), r); }
};

vector<pto> interCC(circle &a, circle &b) {
    vector<pto> r;
    double d = dist(a.p, b.p);
    if (gr(d, a.r + b.r) || le(d + min(a.r, b.r), max(a.r, b.r))) return r;
    double x = (d*d + a.r*a.r - b.r*b.r) / (2*d);
    double y = sqrt(a.r*a.r - x*x);
    pto v = (b.p - a.p) / d;
    r.pb(a.p + v*x + CCW90(v)*y);
    if (gr(y, 0)) r.pb(a.p + v*x - CCW90(v)*y);
    return r;
}
