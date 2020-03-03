bool isConvex(vi &p) { //O(N), delete collinear points!
	int n = sz(p);
	if (n < 3) return false;
	bool isLeft = p[0].left(p[1], p[2]);
	forsn(i, 1, n)
		if (p[i].left(p[(i+1) % n], p[(i+2) % n]) != isLeft)
			return false;
	return true; 
}
