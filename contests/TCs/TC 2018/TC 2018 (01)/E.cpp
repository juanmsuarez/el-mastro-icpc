#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(i-nt i=(int)(s);i<(int)(n);i++)
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

int op(int r,int g,int b,int mix){
    r-=mix;
    g-=mix;
    b-=mix;
    return mix + r/3 + g/3 + b/3;
}


int main() {
    fastio;

    int r,g,b; cin >> r >> g >> b;
    int res=0;
    forn(i,1+min(3,min(r,min(g,b)))){
        res = max(res,op(r,g,b,i));
    }
    cout << res<<endl;

    return 0;
}
