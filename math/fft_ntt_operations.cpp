//Polynomial division: O(n*log(n))
//Multi-point polynomial evaluation: O(n*log^2(n))
//Polynomial interpolation: O(n*log^2(n))

//Works with NTT. For FFT, just replace add,sub,mul,inv,divide
poly add(poly &a, poly &b){
    int n=si(a),m=si(b);
    poly ans(max(n,m));
    forn(i,max(n,m)){
        if(i<n) ans[i]=add(ans[i],a[i]);
        if(i<m) ans[i]=add(ans[i],b[i]);	
    }
    while(si(ans)>1&&!ans.back())ans.pop_back();
    return ans;
}

/// B(0) != 0 !!!
poly invert(poly &b, int d){
    poly c = {inv(b[0])};
    while(si(c)<=d){
        int j=2*si(c);
        auto bb=b; bb.resize(j);
        poly cb=multiply(c,bb);
        forn(i,si(cb)) cb[i]=sub(0,cb[i]);
        cb[0]=add(cb[0],2);
        c=multiply(c,cb);
        c.resize(j);
    }
    c.resize(d+1);
    return c;
}

pair<poly,poly> divslow(poly &a, poly &b){
    poly q,r=a;
    while(si(r)>=si(b)){
        q.pb(divide(r.back(),b.back()));
        if(q.back()) forn(i,si(b)){
            r[si(r)-i-1]=sub(r[si(r)-i-1],mul(q.back(),b[si(b)-i-1]));
        }
        r.pop_back();
    }
    reverse(all(q));
    return {q,r};
}

pair<poly,poly> divide(poly &a, poly &b){	//returns {quotient,remainder}
    int m=si(a),n=si(b),MAGIC=750;
    if(m<n) return {{0},a};
    if(min(m-n,n)<MAGIC)return divslow(a,b);
    poly ap=a; reverse(all(ap));
    poly bp=b; reverse(all(bp));
    bp=invert(bp,m-n);
    poly q=multiply(ap,bp);
    q.resize(si(q)+m-n-si(q)+1,0);
    reverse(all(q));
    poly bq=multiply(b,q);
    forn(i,si(bq)) bq[i]=sub(0,bq[i]);
    poly r=add(a,bq);
    return {q,r};
}

vector<poly> tree;

void filltree(vector<tf> &x){
    int k=si(x);
    tree.resize(2*k);
    forsn(i,k,2*k) tree[i]={sub(0,x[i-k]),1};
    for(int i=k-1;i;i--) tree[i]=multiply(tree[2*i],tree[2*i+1]);
}

vector<tf> evaluate(poly &a, vector<tf> &x){
    filltree(x);
    int k=si(x);
    vector<poly> ans(2*k);
    ans[1]=divide(a,tree[1]).snd;
    forsn(i,2,2*k) ans[i]=divide(ans[i>>1],tree[i]).snd;
    vector<tf> r; forn(i,k) r.pb(ans[i+k][0]);
    return r;
}

poly derivate(poly &p){
    poly ans(si(p)-1);
    forsn(i,1,si(p)) ans[i-1]=mul(p[i],i);
    return ans;
}

poly interpolate(vector<tf> &x, vector<tf> &y){
    filltree(x);
    poly p=derivate(tree[1]);
    int k=si(y);
    vector<tf> d=evaluate(p,x);
    vector<poly> intree(2*k);
    forsn(i,k,2*k) intree[i]={divide(y[i-k],d[i-k])};
    for(int i=k-1;i;i--){
        poly p1=multiply(tree[2*i],intree[2*i+1]);
        poly p2=multiply(tree[2*i+1],intree[2*i]);
        intree[i]=add(p1,p2);
    }
    return intree[1];
}
