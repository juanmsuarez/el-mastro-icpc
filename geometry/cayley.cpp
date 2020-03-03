const double EPS = 1e-9;

struct Mat {
    vector<vector<double> > vec;
    Mat(int n): vec(n, vector<double>(n) ) {}
    Mat(int n, int m): vec(n, vector<double>(m) ) {}
    vector<double> &operator[](int f){return vec[f];}
    const vector<double> &operator[](int f) const {return vec[f];}
    int size() const {return si(vec);}
    Mat operator+(Mat &b) { ///this de n x m entonces b de n x m
        Mat m(si(b),si(b[0]));
        forn(i,si(vec)) forn(j,si(vec[0])) m[i][j] = vec[i][j] + b[i][j];
        return m;    }
    Mat operator*(const Mat &b) { ///this de n x m entonces b de m x t
        int n = si(vec), m = si(vec[0]), t = si(b[0]);
        Mat mat(n,t);
        forn(i,n) forn(j,t) forn(k,m) mat[i][j] += vec[i][k] * b[k][j];
        return mat;    }
    double determinant(){//sacado de e maxx ru
        double det = 1;
        int n = si(vec);
        Mat m(*this);
        forn(i, n){//para cada columna
            int k = i;
            forsn(j, i+1, n)//busco la fila con mayor val abs
                if(abs(m[j][i])>abs(m[k][i])) k = j;
            if(abs(m[k][i])<EPS) return 0;
            m[i].swap(m[k]);//la swapeo
            if(i!=k) det = -det;
            det *= m[i][i];
            forsn(j, i+1, n) m[i][j] /= m[i][i];
            //hago 0 todas las otras filas
            forn(j, n) if (j!= i && abs(m[j][i])>EPS)
                forsn(k, i+1, n) m[j][k]-=m[i][k]*m[j][i];
        }
        return det;
    }
};

double d[5][5]; 

double sqr(double x) { return x*x; }

double init_cayley_menger() { // en los demas d[i][j] va la longitud del lado del vertice i al vertice j
    for (int i = 0; i < 4; i++) d[i][4] = d[4][i] = 1;
}
double cayley_menger(vector<int> idx) { // idx = indices de vertices, por ej {0, 1, 2, 3} en 3d
    idx.push_back(4);
    int n = (int) idx.size();

    Mat mat(n, n);
    forn(i,n) forn(j,n) mat[i][j] = sqr(d[idx[i]][idx[j]]);

    double ans = mat.determinant();
    forn(i,n-2) ans /= -2*(i+1)*(i+1);
    return sqrt(-ans);
}

// https://www.spoj.com/problems/TETRA/
int main() {
    int T; cin >> T;
    cout << fixed << setprecision(4);
    init_cayley_menger();
    while (T--) {
        forn(i,4) forsn(j,i+1,4) {
            int d_ij; cin >> d_ij;
            d[i][j] = d[j][i] = d_ij;
        }
        auto volume = cayley_menger({0,1,2,3});
        double area = 0;
        forn(i,4) area += cayley_menger({i, (i+1)%4, (i+2)%4});
        cout << 3*volume/area << '\n';
    }
    return 0;
}
