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

#define MAXWK 30000

int main() {
	fastio;
	
    ll l,m;
    cin >> l >> m;
    cin.get();

    vector<string> res = {"no such mower"};
    ll priceres = 1e9;

    const int t_s = 10080;

    forn(_,m){
        string name,tmp;
        getline(cin,name,',');
        //D(name);
        ll p,c,t,r;
        getline(cin,tmp,',');
        p=stoi(tmp);
        getline(cin,tmp,',');
        c=stoi(tmp);
        getline(cin,tmp,',');
        t=stoi(tmp);
        getline(cin,tmp);
        r=stoi(tmp);

        //cerr << c << " " << t << " " << r << endl;

        bool can=true;
        forsn(k,1,MAXWK){
            ll cortes = (l*k+c*t-1ll)/(c*t);
            can=(l*k+c-1)/c+r*(cortes-1ll)<=t_s*k;
            if(!can){
                break;
            }
        }
        if(can){
            if(p<priceres){
                priceres=p;
                res = {name};
            }
            else if(p==priceres)res.pb(name);
        }
    }
    for(string r:res)cout << r << endl;
	
	return 0;
}

