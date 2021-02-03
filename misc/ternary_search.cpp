// Minimizes f(x) (change < by > to maximize):
double ts(double l, double r){    
    forn(i,200){
        if(f(l) < f(r)) r -= (r-l)/3;
        else l += (r-l)/3;
    }
    return f(l);
}
