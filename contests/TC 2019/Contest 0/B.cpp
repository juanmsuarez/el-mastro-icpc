#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

ll best(ll m,ll n,ll den){
    ll k1 = (m*den)/n,
        k2 = (m*den+n-1)/n;
    return (den*m-k1*n < k2*n-den*m) ? k1:k2;
}

int main() {
	fastio;
	
	ll m,n,k,p;
    while(cin >> m >> n, m!=-1 && n!=-1){
        k = best(m,n,20),
        p = best(m,n,100);
        string res = string(k,'*')+string(20-k,'-');
        string per = to_string(p)+"%";
        int pos = (20-si(per)+1)/2;
        forn(i,si(per))res[pos+i]=per[i];
        cout << res << endl;
    }

	return 0;
}

