struct Mat {
    vector<vector<double> > rows;
    Mat(int n): rows(n, vector<double>(n)) {}
    Mat(int n, int m): rows(n, vector<double>(m)) {}

    vector<double> &operator[](int f) { return rows[f]; }
    int size() { return si(rows); }

    Mat operator+(Mat &b) { // this de n x m entonces b de n x m
        Mat m(si(rows), si(rows[0]));
        forn(i, si(rows)) forn(j, si(rows[0])) m[i][j] = rows[i][j] + b[i][j];
        return m;    
    }
    Mat operator*(Mat &b) { // this de n x m entonces b de m x t
        int n = si(rows), m = si(rows[0]), t = si(b[0]);
        Mat mat(n, t);
        forn(i, n) forn(j, t) forn(k, m) mat[i][j] += rows[i][k] * b[k][j];
        return mat;    
    }
    Mat operator^(int e) { // this debe ser matriz cuadrada
        int n = si(rows);
        Mat res(n); forn(i, n) res[i][i] = 1;

        Mat base = *this;
        while (e > 0) {
            if (e % 2 == 1) res = res * base;
            base = base * base;
            e /= 2;
        }

        return res;
    }
};
// to calculate determinants, use determinant.cpp
