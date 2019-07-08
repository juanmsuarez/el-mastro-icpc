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

const ll INF = 1E18;

map<char,ll> process(string s){
    int ind=0;
    map<char,ll>res;
    while(ind<si(s)){
        char elem = s[ind++];
        ll cant = 0;
        while(ind< si(s) && '0' <= s[ind] && s[ind] <= '9'){
            cant = cant*10 + s[ind] - '0';
            ind++;
        }
        if(!cant)cant=1;
        res[elem]+=cant;
    }
    return res;
}

int main() {
	fastio;
	
    string a,b;
    ll n;
    cin >> a >> n >> b;

    map<char,ll> elemAs = process(a),
        elemBs = process(b);

    ll res = INF;
    for(auto p:elemBs){
        D(p.fst),D(p.snd);
        if(p.snd)
            res =  min(res,(n*elemAs[p.fst])/p.snd);
    }

    cout << res << endl;

	
	return 0;
}

