// pre[i] = max borde de s[0..i]
vi prefix_function(string &s) {
    int n = si(s); vi pre(n);
    forsn(i, 1, n) {
        int j = pre[i-1];
        while (j > 0 && s[i] != s[j]) j = pre[j-1];
        if (s[i] == s[j]) j++;
        pre[i] = j;
    }
    return pre;
}

vi find_occurrences(string &s, string &t) { //apariciones de t en s
    vi pre = prefix_function(t), res; 
    int n = si(s), m = si(t), j = 0; 
    forn(i, n) {
        while (j > 0 && s[i] != t[j]) j = pre[j-1]; 
        if (s[i] == t[j]) j++;
        if (j == m) { 
            res.pb(i-j+1); 
            j = pre[j-1]; 
        } 
    } 
    return res; 
}

// aut[i][c] = (next o failure function) al intentar matchear s[i] con c
void compute_automaton(string s, vector<vi>& aut) {
    s += '#'; // separador!
    int n = si(s);
    vi pi = prefix_function(s);
    aut.assign(n, vi(26));

    forn(i, n) forn(c, 26)
        if (i > 0 && 'a' + c != s[i])
            aut[i][c] = aut[pi[i-1]][c];
        else
            aut[i][c] = i + ('a' + c == s[i]);
}
