int z[N]; // z[i] = i==0 ? 0 : max k tq s[0,k) match with s[i,i+k)
void z_function(string &s, int z[]) {
    int n = si(s);
    forn(i,n) z[i]=0;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])  ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
}
