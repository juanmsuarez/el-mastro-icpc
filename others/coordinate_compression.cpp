void compress(vi &a){ // O(n lg n)
    vi b(a); sort(all(b));
    b.erase(unique(all(b)), b.end());
    for(int &x:a) x = int(lower_bound(all(b),x) - b.begin());
}