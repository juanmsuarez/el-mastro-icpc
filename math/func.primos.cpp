// TODO: actualizar macros. Ver que sean compatibles con criba
// INCLUIR CRIBA

//factoriza bien numeros hasta MAXP^2
map<ll,ll> fact(ll n){ //O (cant primos)
	map<ll,ll> ret;
	for (ll p : primos){
		while(!(n%p)){
			ret[p]++;//divisor found
			n/=p;
		}
	}
	if(n>1) ret[n]++;
	return ret;
}
//factoriza bien numeros hasta MAXP
map<ll,ll> fact2(ll n){ //O (lg n)
	map<ll,ll> ret;
	while (criba[n]){
		ret[criba[n]]++;
		n/=criba[n];
	}
	if(n>1) ret[n]++;
	return ret;
}
//Usar asi:  divisores(fac, divs, fac.begin()); NO ESTA ORDENADO
void divisores(const map<ll,ll> &f, vector<ll> &divs, map<ll,ll>::iterator it, ll n=1){
    if(it==f.begin()) divs.clear();
    if(it==f.end()) { divs.pb(n);  return; }
    ll p=it->fst, k=it->snd; ++it;
    forn(_, k+1) divisores(f, divs, it, n), n*=p;
}
ll sumDiv (ll n){
  ll rta = 1;
  map<ll,ll> f=fact(n);
  forall(it, f) {
	ll pot = 1, aux = 0;  
	forn(i, it->snd+1) aux += pot, pot *= it->fst;
	rta*=aux;
  } 
  return rta;
}
ll eulerPhi (ll n){ // con criba: O(lg n)
  ll rta = n;
  map<ll,ll> f=fact(n);
  forall(it, f) rta -= rta / it->first;
  return rta;
}
ll eulerPhi2 (ll n){ // O (sqrt n)
	ll r = n;
	forr (i,2,n+1){
		if ((ll)i*i > n) break;
		if (n % i == 0){
			while (n%i == 0) n/=i;
			r -= r/i; }
	}
	if (n != 1) r-= r/n;
	return r;
}
