
#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
    #define RAYA cerr << "----------" << endl
#else
    #define DBG(a)
    #define RAYA
    #define endl '\n'
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

string col[]={"red","yellow","green","brown","blue","pink","black"};
map<string,int>ind;

int main() {
	fastio;
    forn(i,7){
        ind[col[i]]=i;
    }

    int n;
    cin >>n;
    vi cant(7,0);
    forn(i,n){
        string a;
        cin>>a;
        cant[ind[a]]++;
    }

    int best=0;
    forsn(i,1,si(cant))best=(cant[i]?i+1:best);
    int res = (best?(best+1)*cant[0]:1);
    forsn(i,1,si(cant))res+=cant[i]*(i+1);


    cout << res << endl;
	return 0;
}
