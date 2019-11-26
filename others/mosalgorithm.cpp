const int Q = 2e5, SQ = 200;

struct Query { // [l, r)
    int l,r,id;
    bool operator<(const Query &q){
        if(l/SQ != q.l/SQ) return l < q.l;
        return l/SQ & 1 ? r < q.r : r > q.r;
    }
} qs[Q];

int ans[Q],res,pl,pr; // ans[i] = ans to ith query

void mo(int m){ // O( (n+q) * sqrt(n) * (add() + remove()) )
    forn(i,m) qs[i].id = i;
    sort(qs, qs + m);
    pl = 0, pr = 0, res = 0;
    forn(i,m){
        Query &q = qs[i];
        while(pl > q.l) add(--pl);
        while(pr < q.r) add(pr++);
        while(pl < q.l) remove(pl++);
        while(pr > q.r) remove(--pr);
        ans[q.id] = res;
    }
}
