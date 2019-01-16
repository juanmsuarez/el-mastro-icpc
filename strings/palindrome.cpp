bool palindrome(ll x){
	string s = to_string(x); int n = si(s);
	forn(i,n/2) if(s[i] != s[n-i-1]) return 0;
	return 1;
}
