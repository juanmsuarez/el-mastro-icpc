const double EPS = 1e-9;
struct pto {
	double x, y;
	pto(double x=0, double y=0) : x(x),y(y) {}
	pto operator+(pto a) { return pto(x + a.x, y + a.y); }
	pto operator-(pto a) { return pto(x - a.x, y - a.y); }
	pto operator+(double a) { return pto(x + a, y + a); }
	pto operator*(double a) { return pto(x*a, y*a); }
	pto operator/(double a) { return pto(x/a, y/a); }
	double norm() { return sqrt(x*x + y*y); }
	double norm2() { return x*x + y*y; }
    // Dot product:
	double operator*(pto a){ return x*a.x + y*a.y; }
	// Magnitude of the cross product (if a is less than 180 CW from b, a^b > 0):
	double operator^(pto a) { return x*a.y - y*a.x; }
	// Returns true if this point is at the left side of line qr:
	bool left(pto q, pto r) { return ((q - *this) ^ (r - *this)) > 0; }
	bool operator<(const pto &a) const { 
        return x < a.x - EPS || (abs(x - a.x) < EPS && y < a.y - EPS); 
    }
    bool operator==(pto a) {
        return abs(x - a.x) < EPS && abs(y - a.y) < EPS;
    }
};
double dist(pto a, pto b) { return (b-a).norm(); }
double dist2(pto a, pto b) { return (b-a).norm2(); }
typedef pto vec;
double angle(pto a, pto o, pto b){ // [-pi, pi]
	pto oa = a-o, ob = b-o;
	return atan2(oa^ob, oa*ob);
}
// Rotate around the origin:
pto rotateCCW90(pto p) { return pto(-p.y, p.x); }
pto rotateCW90(pto p) { return pto(p.y, -p.x); }
pto rotateCCW(pto p, double t){ // rads
	return pto(p.x*cos(t) - p.y*sin(t), p.x*sin(t) + p.y*cos(t));
}
