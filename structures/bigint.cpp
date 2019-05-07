#define BASE 10
#define LMAX 1000
int pad(int x){
    x--; int c = 0;
    while(x) x /= 10, c++;
    return c; 
}
const int PAD = pad(BASE);
struct bint {
    int l;
    ll n[LMAX];
    bint(ll x = 0){
        l = 1;
        forn(i,LMAX){
          if(x) l = i+1;
          n[i] = x % BASE;
          x /= BASE;
        }
    }
    bint(string x){
        int sz = si(x);
        l = (sz-1)/PAD + 1;
        fill(n, n+LMAX, 0);
        ll r = 1;
        forn(i,sz){
            if(i % PAD == 0) r = 1;
            n[i/PAD] += r*(x[sz-1-i]-'0');
            r *= 10;
        }
    }
    void out() const {
        cout << n[l-1] << setfill('0');
        dforn(i,l-1) cout << setw(PAD) << n[i];
    }
    void invar(){
        fill(n+l, n+LMAX, 0);
        while(l > 1 && !n[l-1]) l--;
    }
};
bint operator+(const bint &a, const bint &b){
    bint c;
    c.l = max(a.l, b.l);
    ll q = 0;
    forn(i,c.l){
        q += a.n[i] + b.n[i]; 
        c.n[i] = q % BASE;
        q /= BASE;
    }
    if(q) c.n[c.l++] = q;
    c.invar();
    return c;
}
pair<bint,bool> lresta(const bint &a, const bint &b){ // c = a - b
    bint c;
    c.l = max(a.l, b.l);
    ll q = 0;
    forn(i,c.l){
        q += a.n[i] - b.n[i];
        c.n[i] = (q + BASE) % BASE;
        q = (q + BASE)/BASE - 1;
    }
    c.invar();
    return {c,!q};
}
bint &operator -=(bint &a, const bint &b){ return a = lresta(a, b).fst; }
bint operator -(const bint &a, const bint &b){ return lresta(a, b).fst; }
bool operator <(const bint &a, const bint &b){ return !lresta(a, b).snd; }
bool operator <=(const bint &a, const bint &b){ return lresta(b, a).snd; }
bool operator ==(const bint &a, const bint &b){ return a <= b && b <= a; }
bool operator !=(const bint &a, const bint &b){ return a < b || b < a; }
bint operator *(const bint &a, ll b){
    bint c;
    ll q = 0;
    forn(i,a.l){
        q += a.n[i]*b;
        c.n[i] = q % BASE;
        q /= BASE;
    }
    c.l = a.l;
    while(q){
        c.n[c.l++] = q % BASE;
        q /= BASE;
    }
    c.invar();
    return c;
}
bint operator *(const bint &a, const bint &b){
    bint c;
    c.l = a.l+b.l;
    fill(c.n, c.n+b.l, 0);
    forn(i,a.l){
        ll q = 0;
        forn(j,b.l){
            q += a.n[i]*b.n[j] + c.n[i+j];
            c.n[i + j] = q % BASE;
            q /= BASE;
        }
        c.n[i+b.l] = q;
    }
    c.invar();
    return c;
}
pair<bint,ll> ldiv(const bint &a, ll b){ // c = a / b ; rm = a % b
	bint c;
	ll rm = 0;
	dforn(i,a.l){
        rm = rm*BASE + a.n[i];
        c.n[i] = rm/b;
        rm %= b;
    }
    c.l = a.l;
    c.invar();
    return {c,rm};
}
bint operator /(const bint &a, ll b){ return ldiv(a, b).fst; }
ll operator %(const bint &a, ll b){ return ldiv(a, b).snd; }
pair<bint,bint> ldiv(const bint &a, const bint &b){
    bint c, rm = 0;
    dforn(i,a.l){
        if(rm.l == 1 && !rm.n[0]) rm.n[0] = a.n[i];
        else {
            dforn(j,rm.l) rm.n[j+1] = rm.n[j];
            rm.n[0] = a.n[i], rm.l++;
        }
        ll q = rm.n[b.l]*BASE + rm.n[b.l-1];
        ll u = q / (b.n[b.l-1] + 1);
        ll v = q / b.n[b.l-1] + 1;
        while(u < v-1){
            ll m = (u + v)/2;
            if(b*m <= rm) u = m;
            else v = m;
        }
        c.n[i] = u, rm -= b*u;
    }
    c.l = a.l;
    c.invar();
    return {c,rm};
}
bint operator /(const bint &a, const bint &b){ return ldiv(a, b).fst; }
bint operator %(const bint &a, const bint &b){ return ldiv(a, b).snd; }
bint gcd(bint a, bint b){ 
    while(b != bint(0)){
        bint r = a % b;
        a = b, b = r;
    }
    return a;
}
