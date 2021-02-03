vi compress(vi &a) { // O(n lg n)
    vi b(a); sort(all(b)), b.erase(unique(all(b)), end(b));
    for (int &x : a) x = int(lower_bound(all(b), x) - begin(b));
    return b; // b[x] = original value of x
}
