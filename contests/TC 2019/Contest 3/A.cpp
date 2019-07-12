
#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s, n) for (int i = (int)s; i < (int)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define snd second
#define si(a) ((int)(a).size())
#define pb emplace_back
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;



int main() {
    int n;
    cin >> n;

    ll res = 2;
    forsn(i,2,n){
        res+=2;
        forsn(j,2,i){
            ll cuts = (j-1) * (i-j);
            res += cuts+1;
        }
        //cerr << "R " << res << endl;
    }


    if(n<=1)cout << 1 << endl;
    else cout << res << endl;
}
