struct segm {
	pto s, f;
	segm(pto s, pto f) : s(s), f(f) {}
	pto closest(pto p) { // use for dist to point
	   double l2 = dist2(s, f);
	   if (l2 == 0.) return s;
	   double t = ((p-s) * (f-s)) / l2;
	   if (t < 0.) return s; // don't write if its a line
	   else if (t > 1.) return f; // don't write if its a line
	   return s + ((f-s) * t);
	}
    bool inside(pto p) { return abs(dist(s, p) + dist(p, f) - dist(s, f)) < EPS; }
};

// Note: if the segments are collinear it only returns a point of intersection
pto inter(segm &s1, segm &s2){
    if (s1.inside(s2.s)) return s2.s; // if they are collinear
    if (s1.inside(s2.f)) return s2.f; // if they are collinear
	pto r = inter(line(s1.s, s1.f), line(s2.s, s2.f));
    if (s1.inside(r) && s2.inside(r)) return r;
	return pto(INF, INF);
}
