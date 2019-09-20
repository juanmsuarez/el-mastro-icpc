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

const int MAXN = 200+10;

bitset<MAXN>worse[MAXN];
vi adj[MAXN];

map<string,int>country;
int ind=0;

int id(string s){
    if(country.count(s))return country[s];
    return country[s]=ind++;
}

void dfs(int r,int u){
    for(int v:adj[u]){
        worse[r][v]=true;
        dfs(r,v);
    }
}

void parse(string& a,string& b){
    string line;
    getline(cin,line);
    D(line);
    vector<string> toks;
    size_t pos;
    while(pos=line.find(' '),pos!=string::npos){
        toks.pb(line.substr(0,pos));
        //D(toks.back());
        line = line.substr(pos+1);
    }
    toks.pb(line);
    //D(line);
    a=toks[0];
    b=toks[4];
}

int main() {
	fastio;
	
    int n,m;
    cin >> n >> m;
    
    {
        string s;
        getline(cin,s);
    }
    forn(i,n){
        string a,b;
        parse(a,b);

        adj[id(a)].pb(id(b));
        
    }

    forn(u,n){
        dfs(u, u);
    }

    forn(i,m){
        string a,b;
        parse(a,b);
        if(worse[id(a)][id(b)]){
            cout << "Fact" << endl;
        }
        else if (worse[id(b)][id(a)])
            cout << "Alternative Fact" << endl;
        else cout << "Pants on Fire" << endl;
    }
	
	return 0;
}

