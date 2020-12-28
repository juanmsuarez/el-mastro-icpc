const double EPS = 1e-9;
const int INF = 1e9; // it doesn't actually have to be infinity or a big number

int gauss(Mat mat, vector<double> &ans) { // returns number of solutions
    int n = si(mat);
    int m = n > 0 ? si(mat[0]) - 1 : 0;

    vi where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; col++) { // for each col
        int sel = row;
        forsn(i, row, n) // row with largest abs val to avoid floating point errors
            if (abs(mat[i][col]) > abs(mat[sel][col])) 
                sel = i;
        if (abs(mat[sel][col]) < EPS)
            continue;
        swap(mat[sel], mat[row]); // move pivot row
        where[col] = row;

        forn(i, n) if (i != row) { // zero out other rows
            double c = mat[i][col] / mat[row][col];
            forsn(j, col, m + 1) 
                mat[i][j] -= mat[row][j] * c;
        }
        row++;
    }

    ans.assign(m, 0);
    forn(i, m)
        if (where[i] != -1)
            ans[i] = mat[where[i]][m] / mat[where[i]][i]; // calculate x_i
    forn(i, n) { // check if the solution is valid (also possible to check: if a row has all zero-coefficients -> the constant term is also zero)
        double sum = 0;
        forn(j, m) 
            sum += ans[j] * mat[i][j];
        if (abs(sum - mat[i][m]) > EPS)
            return 0;
    }

    forn(i, m)
        if (where[i] == -1)
            return INF;
    return 1;
}

// SPEED IMPROVEMENT IF MOD 2:
int gauss(vector<bitset<N>> a, int n, int m, bitset<N> &ans) {
    vi where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; col++) {
        forsn(i, row, n)
            if (a[i][col]) {
                swap(a[i], a[row]);
                break;
            }
        if (!a[row][col])
            continue;
        where[col] = row;

        forn(i, n)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        row++;
    }
    // The rest of implementation is the same as above
}
