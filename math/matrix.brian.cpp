#define tipo ll // Cambiar a double de ser necesario
struct Mat {
    vector<vector<tipo>> vec;
    Mat(int n): vec(n, vector<tipo>(n) ) {}
    Mat(int n, int m): vec(n, vector<tipo>(m) ) {}
    vector<tipo> &operator[](int f){ return vec[f]; }
    const vector<tipo> &operator[](int f) const { return vec[f]; }
    int size() const { return vec.size(); }
};
Mat operator+ (Mat A, Mat B) { ///this de n x m entonces b de n x m
    Mat ans(B.size(), B[0].size());
    forn(i, A.size()) forn(j, A[0].size()) ans[i][j] = A[i][j] + B[i][j];
    return ans;
}
Mat operator* (Mat A, double c) { ///this de n x m entonces b de n x m
    Mat ans(A.size(), A[0].size());
    forn(i, A.size()) forn(j, A[0].size()) ans[i][j] = A[i][j] * c;
    return ans;
}
Mat operator* (Mat A, Mat B) { ///this de n x m entonces b de m x t
    int n = A.size(), m = A[0].size(), t = B[0].size();
    Mat ans(n, t);
    forn(i, n) forn(j, t) forn(k, m) 
      // Retirar MOD si la matriz es real
      ans[i][j] = (ans[i][j] + A[i][k] * B[k][j] % MOD) % MOD; 
    return ans;
}
double det(Mat _A){ // sacado de e maxx ru
    int n = _A.size();
    double A[n][n];
    forn(i, n) forn(j, n) A[i][j] = _A[i][j];
    forn(i, n){
        forn(j, n){ if(j) cout << " "; cout << A[i][j]; }
        cout << endl;
    }
    double ans = 1;
    forn(i, n){ // para cada columna
        int k = i;
        forr(j, i+1, n) // busco la fila con mayor val abs
            if(abs(A[j][i]) > abs(A[k][i])) k = j;
        if(abs(A[k][i]) < 1e-9) return 0;
        forn(j, n){ swap(A[i][j], A[k][j]); } // la swapeo
        if(i != k) ans = -ans;
        ans *= A[i][i];
        forr(j, i+1, n) A[i][j] /= A[i][i];
        forn(j, n) if(j != i && abs(A[j][i]) > 1e-9 )
            forr(k, i+1, n) A[j][k] -= A[i][k] * A[j][i];
    }
    return ans;
}
Mat operator^(Mat A, ll e){ // O(n^3 log e)
	Mat ans(A.size());
	int n = A.size();
	forn(i, n) forn(j, n) ans[i][j] = (i == j); // Matriz identidad
	if(!e) return ans; // Devuelvo la identidad
	Mat B = A^(e/2); B = (B * B);
	return (e % 2 ? (A * B) : B);
}
