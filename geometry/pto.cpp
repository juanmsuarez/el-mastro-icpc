const double EPS = 1e-9;
struct Point {
	double x, y;
	Point(double _x=0, double _y=0) : x(_x),y(_y) {}
	Point operator+(Point a) { return Point(x + a.x, y + a.y); }
	Point operator-(Point a) { return Point(x - a.x, y - a.y); }
	Point operator+(double a) { return Point(x + a, y + a); }
	Point operator*(double a) { return Point(x*a, y*a); }
	Point operator/(double a) { return Point(x/a, y/a); }
	double norm() { return sqrt(x*x + y*y); }
	double norm2() { return x*x + y*y; }
    // Dot product:
	double operator*(Point a){ return x*a.x + y*a.y; }
	// Magnitude of the cross product (if a is less than 180 CW from b, a^b > 0):
	double operator^(Point a) { return x*a.y - y*a.x; }
	// Returns true if this point is at the left side of line qr:
	bool left(Point q, Point r) { return ((q - *this) ^ (r - *this)) > 0; }
	bool operator<(const Point &a) const { 
        return x < a.x - EPS || (abs(x - a.x) < EPS && y < a.y - EPS); 
    }
    bool operator==(Point a) {
        return abs(x - a.x) < EPS && abs(y - a.y) < EPS;
    }
};
typedef Point vec;
double dist(Point a, Point b) { return (b-a).norm(); }
double dist2(Point a, Point b) { return (b-a).norm2(); }
double angle(Point a, Point o, Point b){ // [-pi, pi]
	Point oa = a-o, ob = b-o;
	return atan2(oa^ob, oa*ob);
}
// Rotate around the origin:
Point CCW90(Point p) { return Point(-p.y, p.x); }
Point CW90(Point p) { return Point(p.y, -p.x); }
Point CCW(Point p, double t){ // rads
	return Point(p.x*cos(t) - p.y*sin(t), p.x*sin(t) + p.y*cos(t));
}
// Sorts points in CCW order about origin, points on neg x-axis come last
// To change pivot to point x, just substract x from all points and then sort
bool half(Point &p) { return p.y == 0 ? p.x < 0 : p.y > 0; }
bool angularOrder(Point &x, Point &y) { 
	bool X = half(x), Y = half(y);
	return X == Y ? (x ^ y) > 0 : X < Y; 
}
