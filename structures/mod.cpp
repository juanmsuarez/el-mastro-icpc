struct num {
    int a;
    num(int _a = 0) : a(_a) {} // o tambien num(ll _a=0) : a((_a%M+M)%M) {}
    operator int(){ return a; }
    num operator +(num b){ return a+b.a >= M ? a+b.a-M : a+b.a; }
    num operator -(num b){ return a-b.a < 0 ? a-b.a+M : a-b.a; }
    num operator *(num b){ return int((ll)a*b.a % M); } 
    num operator ^(ll e){
		if(!e) return 1;
        num q = (*this)^(e/2);
		return e & 1 ? q*q*(*this) : q*q; 
    }
    num operator ++(int x){ return a++; }
};
int norm(ll x){ return x < 0 ? int(x % M + M) : int(x % M); }
num inv(num x){ return x^(M-2); } // M must be prime
num operator /(num a, num b){ return a*inv(b); } 
num neg(num x){ return x.a ? -x.a+M : 0; }
istream& operator >>(istream &i, num &x){ i >> x.a; return i; }
ostream& operator <<(ostream &o, const num &x){ o << x.a; return o; }
// Cast integral values to num in arithmetic expressions!
