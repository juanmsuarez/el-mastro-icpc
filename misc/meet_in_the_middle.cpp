/* Meet in the middle is a search technique used when the input size is small but not small enough to use direct brute force. 
   We divide the numbers into two sets x and y, sort y, and then iterate over each element of x, and binary search over y.
   Example: determine the maximum sum subset having sum less than or equal v in O(2^(n/2)*n) (max input size ~45).         */

void subsets(vi &a, vi &b, int n, int m, int s){
    forn(i, n) b[1 << i] = a[i + s];
    forn(i, m) b[i] = b[i ^ (i & -i)] + b[i & -i];
}

int max_subset_sum(vi &a, int v){
	int n = si(a), m = n/2;
    int sx = 1 << m, sy = 1 << (n-m);
    vi x(sx), y(sy);
	subsets(a, x, m, sx, 0);
    subsets(a, y, n-m, sy, m);
	sort(all(y));

    int res = 0;
	forn(i, sx) if (x[i] <= v) { 
		int p = int(upper_bound(all(y), v-x[i]) - y.begin() - 1);
		res = max(res, x[i] + y[p]);
	}
	return res;
}
