double determinant(Mat m) { // do gaussian elimination and calculate determinant
    double det = 1;
    int n = si(m);
    forn(i, n) { // for each col
        int k = i;
        forsn(j, i+1, n) // row with largest abs val to avoid floating point errors
            if (abs(m[j][i]) > abs(m[k][i])) 
                k = j;
        if (abs(m[k][i]) < EPS) return 0;
        swap(m[i], m[k]); // move pivot row
        if (i != k) det = -det;
        det *= m[i][i];
        forsn(j, i+1, n) m[i][j] /= m[i][i]; // scale current row
        forn(j, n) if (j != i && abs(m[j][i]) > EPS) // zero out other rows
            forsn(k, i+1, n) 
                m[j][k] -= m[i][k] * m[j][i]; 
    }
    return det;
}

// if mod 2, check gauss.cpp for a faster implementation
