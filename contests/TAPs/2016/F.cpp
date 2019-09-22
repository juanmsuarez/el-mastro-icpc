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

int main() {
	fastio;
	
    int n;
    cin >> n;

    vector<string> names;
    queue<string>leadR,trailD,RD;

    
    forn(i,n){
        string a;
        string aux;
        cin >> a;
        int ind= si(a)-1;;
        while(ind>0&&a[ind]!='D'&&a[ind]!='R')ind--;
        if(a[ind]=='D')aux+="D";
        ind =0; 
        while(ind<si(a)-1&&a[ind]!='D'&&a[ind]!='R')ind++;
        if(a[ind]=='R')aux+="R";
        if(aux=="")names.pb(a);
        if(aux=="D")trailD.emplace(a);
        if(aux=="R")leadR.emplace(a);
        if(aux=="DR")RD.emplace(a);
    }
    if(!trailD.empty()){
        names.pb(trailD.front());
        trailD.pop();
    }
    while(!RD.empty()){
        names.pb(RD.front());
        RD.pop();
    }
    while(!trailD.empty()&&!leadR.empty()){
        names.pb(leadR.front());
        names.pb(trailD.front());
        leadR.pop();
        trailD.pop();
    }

    while(!leadR.empty()){
        names.pb(leadR.front());
        leadR.pop();
    }
    while(!trailD.empty()){
        names.pb(trailD.front());
        trailD.pop();
    }



    char nxt[2] = {'D','R'};
    int cant =0;
    for(auto s:names){
        for(char c:s){
            cant+=(c==nxt[cant%2]);
        }
    }
    cout << cant/2 << endl;
    
	
	return 0;
}
