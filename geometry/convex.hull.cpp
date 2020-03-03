// Stores convex hull of P in S in CCW order
// Left must return >= -EPS to delete collinear points!
void chull(vector<pto>& P, vector<pto> &S){
	S.clear(), sort(all(P)); // first x, then y
	forn(i, si(P)) { // lower hull
		while (si(S) >= 2 && S[si(S)-1].left(S[si(S)-2], P[i])) S.pop_back();
		S.pb(P[i]);
	}
	S.pop_back();
	int k = si(S);
	dforn(i, si(P)) { // upper hull
		while (si(S) >= k+2 && S[si(S)-1].left(S[si(S)-2], P[i])) S.pop_back();
		S.pb(P[i]);
	}
	S.pop_back();
}
