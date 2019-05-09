const int mod = 998244353;
struct num {
    int a;
    num(int b = 0){ a = b; }
    operator int(){ return a; }
    num operator +(num b){ return a+b.a > mod ? a+b.a-mod : a+b.a; }
    num operator -(num b){ return a-b.a < 0 ? a-b.a+mod : a-b.a; }
    num operator *(num b){ return int(ll(a)*b.a % mod); } 
    num operator ^(num e){
		if(!e.a) return 1;
        num q = (*this)^num(e.a/2);
		return e.a & 1 ? q*q*(*this) : q*q; 
    }
    num operator ++(int x){ return a++; }
};
int norm(ll x){ return x < 0 ? int(x % mod + mod) : int(x % mod); }
num inv(num x){ return x^num(mod-2); } // mod must be prime
num operator /(num a, num b){ return a*inv(b); } 
num neg(num x){ return x.a ? -x.a+mod : 0; }
istream& operator >>(istream &i, num &x){ i >> x.a; return i; }
ostream& operator <<(ostream &o, const num &x){ o << x.a; return o; }
// Cast integral values to num in arithmetic expressions!
