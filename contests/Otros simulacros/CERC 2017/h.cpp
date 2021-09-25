#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl
#else 
    #define D(a) 8 
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define all(a) (a).begin(),(a).end()
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MAXN = 1010;
map<string,ll> directory;
map<string,vector<string>>subdirs;

ll t;

void dfs(string dirName){
    if(si(subdirs[dirName])){
        ll maxSub =0;
        for(string sub:subdirs[dirName])
            maxSub=max(maxSub,directory[sub]);
        if(maxSub>=t){
            cout << "- " << dirName << " " << directory[dirName] << endl;  
            sort(all(subdirs[dirName]));
            for(string sub:subdirs[dirName])
                dfs(sub);
        }
        else cout << "+ " << dirName << " " << directory[dirName] << endl;  
    }
    else cout << "  " << dirName << " " << directory[dirName] << endl;
}

int main() {
    fastio;

    int n;
    cin >> n;
    directory = {{"/",0}};

    forn(i,n){
        string file;
        ll fileSz;
        cin >> file >> fileSz;
        int pos =-1;
        string prev = "";
        while(pos = file.find('/',pos+1),pos!=string::npos){
            string dirName = file.substr(0,pos+1);
            if(!directory.count(dirName)){
                subdirs[prev].pb(dirName);
            }
            directory[dirName]+=fileSz;
            prev=dirName;
        }
    }

    cin >> t;
    dfs("/");
    
    
    return 0;
}

