void manacher(string s, vi &odd, vi &even) {
    int n = si(s);
    s = "@" + s + "$";
    odd = vi(n), even = vi(n);
    int l = 0, r = -1;
    forn(i, n) {
        int k = i > r ? 1 : min(odd[l+r-i], r-i+1);
        while (s[i+1-k] == s[i+1+k]) k++;
        odd[i] = k--;
        if (i+k > r) l = i-k, r = i+k;
    }
    l = 0, r = -1;
    forn(i, n) {
        int k = i > r ? 0 : min(even[l+r-i+1], r-i+1);
        while (s[i-k] == s[i+1+k]) k++;
        even[i] = k--;
        if (i+k > r) l = i-k-1, r = i+k;
    }
}
