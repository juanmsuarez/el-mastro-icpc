// pre[i] = max border of s[0..i]
vi prefix_function(string &s) {
    int n = si(s), j = 0; vi pre(n);
    forsn(i, 1, n) {
        while (j > 0 && s[i] != s[j]) j = pre[j-1];
        pre[i] = s[i] == s[j] ? ++j : j;
    }
    return pre;
}

vi find_occurrences(string &s, string &t) { // occurrences of s in t
    vi pre = prefix_function(s), res; 
    int n = si(s), m = si(t), j = 0; 
    forn(i, m) {
        while (j > 0 && t[i] != s[j]) j = pre[j-1]; 
        if (t[i] == s[j]) j++;
        if (j == n) res.pb(i-n+1), j = pre[j-1]; 
    } 
    return res; 
}

// (i chars match, next_char = c) -> (aut[i][c] chars match)
vector<vi> kmp_automaton(string &s) { 
    s += '#'; int n = si(s);
    vi pre = prefix_function(s);
    vector<vi> aut(n, vi(26)); // alphabet = lowercase letters
    forn(i, n) forn(c, 26) {
        if (i > 0 && 'a' + c != s[i]) 
            aut[i][c] = aut[pre[i-1]][c];
        else 
            aut[i][c] = i + ('a' + c == s[i]);
    }
    return aut;
}
