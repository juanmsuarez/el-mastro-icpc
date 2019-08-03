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

    ll n;
    cin >> n;
    string s;
    cin >> s;
    int h=0,m=0;
    if(n==1)cout << "HM" << endl;
    else{
        forn(i,n-1){
            if(s[i]=='H')h++;
            else m++;
        }
        if(h>m)cout << "H"<<endl;
        else if(h<m)cout << "M"<<endl;
        else{
            if(s[n-2]=='H')cout << "H" << endl;
            else cout << "M" << endl;
        }
    }
    

    return 0;
}
