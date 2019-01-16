#define mod(a,m) ((a)%(m) < 0 ? (a)%(m)+(m) : (a)%(m)) // evita overflow al no sumar si >= 0
typedef tuple<ll,ll,ll> ec;
pair<ll,ll> sol(ec c){ //requires inv, diophantine
    ll a=get<0>(c), x1=get<1>(c), m=get<2>(c), d=gcd(a,m);
    if (d==1) return mp(mod(x1*inv(a,m),m), m);
    else return x1%d ? mp(-1LL,-1LL) : sol({a/d,x1/d,m/d});
}
pair<ll,ll> crt(vector< ec > cond) { // returns: (sol, lcm)
	ll x1=0,m1=1,x2,m2;
	for(auto t:cond){
		tie(x2,m2)=sol(t);
		if((x1-x2)%gcd(m1,m2))return mp(-1,-1);
		if(m1==m2)continue;
		ll k=diophantine(m2,-m1,x1-x2).fst.snd,l=m1*(m2/gcd(m1,m2));
		x1=mod(m1*mod(k, l/m1)+x1,l);m1=l; // evita overflow con prop modulo
	}
	return sol(make_tuple(1,x1,m1));
} //cond[i]={ai,bi,mi} ai*xi=bi (mi); assumes lcm fits in ll
