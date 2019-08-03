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

const int s = 1e6;

bitset<1000000+10> chosen;

int simm(int n){
    return s - (n-1);
}

int main() {
	fastio;
	
	int x;
    cin >> x;
     
    forn(_,x){
        int a;
        cin >> a;
        chosen.set(a);
    }

    vi res;
    int pending=0;
    forn(i,s+1){
        if(chosen[i]){
            if(!chosen[simm(i)])res.pb(simm(i));
            else pending++;
        }
    }

    int ind =1;
    while(pending){
        if(!chosen[ind] && !chosen[simm(ind)]){
            res.pb(ind);
            res.pb(simm(ind));
            pending-=2;
        }
        ind++;
    }

    cout << si(res) << endl;
    string space = "";
    for(int a:res){
        cout << space <<a;
        space = " ";
    }
    cout << endl;
    

	return 0;
}

