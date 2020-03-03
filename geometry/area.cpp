double area(vector<pto> &p) { // O(n)
	double area = 0; int n = si(p);
	forn(i, n) area += p[i] ^ p[(i+1) % n];
	// if points are in CW order then area is negative
	return abs(area) / 2;
}
// Area ellipse = M_PI*a*b where a and b are the semi axis lengths
// Area triangle = sqrt(s*(s-a)(s-b)(s-c)) where s = (a+b+c)/2
