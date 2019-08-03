#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

int main() {
    fastio;

    int n;
    string s;
    cin >> n >> s;
    int dir=0;
    vi val(1,0);
    bool bad=false;
    for(char a:s){
        if(a=='<'){
            if(dir!=1)val.back()=0;
            dir=1;
            val.pb(val.back()+1);
        }
        else if(a=='>'){
            if(dir!=-1)val.back()=n-1;
            dir=-1;            
            val.pb(val.back()-1);
        }
        if(val.back()<0||val.back()>=n){
            bad=true;
            break;
        }
    }
    if(bad)cout << -1 << endl;
    else{
        cout << (char)('a'+val[0]);
        int ind=0;
        for(char a:s){
            if(a!='=')ind++;
            cout << (char)('a'+val[ind]);
        }
        cout << endl;
    }


    return 0;
}

