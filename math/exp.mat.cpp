const int S = 2;
int temp[S][S];
void mul(int a[S][S], int b[S][S]){
    forn(i, S) forn(j, S) temp[i][j] = 0;
    forn(i, S) forn(j, S) forn(k, S) temp[i][j]+=a[i][k]*b[k][j];
    forn(i, S) forn(j, S) a[i][j]=temp[i][j];
}
void powmat(int a[S][S], ll n, int res[S][S]){
    forn(i, S) forn(j, S) res[i][j]=(i==j);
    while (n) {
        if (n&1) mul(res, a); 
        n >>= 1; mul(a, a);
    }
}

