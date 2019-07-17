#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = "  << a << endl
#else
    #define D(a)
#endif
#define forsn(i,s,n) for(int i = (int)s; i < (int)n;i++)
#define forn(i,n) forsn(i,0,n)
#define pb emplace_back
#define si(a) int(a.size())
using vi = vector<int>;
using ll = long long int;


int main(){
    int n;
    cin >> n;
    vi cant(2);
    string s;
    cin >> s;
    forn(i,n){
        if(s[i]=='r')cant[i%2]++;
    }
    int ci = n/2,cp=n-ci,p=cant[0],i=cant[1];
    int res = max(cp-p,i);
    p=cp-cant[0],i=ci-cant[1];
    res = min(res,max(cp-p,i));
    cout << res << endl;

}
