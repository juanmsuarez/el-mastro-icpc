#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i = (int)s; i < (int) n;i++)
#define forn(i,n) forsn(i,0,n)
#define si(a) ((int)(a).size())
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using pii = pair<int,int>;
using ll = long long int;
using vi = vector<int>;

const int N = 5e3;
int n; 
ll memo[N];
string s;

ll dp(int pos) {
    if (pos == n) return 1;

    ll &res = memo[pos];
    if (res != -1) return res;
    res = 0;

    if (s[pos]-'0' > 0) {
            res += dp(pos+1);
            if (pos+1 < n && (s[pos]-'0')*10+(s[pos+1]-'0') <= 26) res += dp(pos+2);
    }

    return res;
}

int main(){
        fastio;

        while (cin >> s && s != "0") {
            n = si(s);

            fill(memo, memo+n, -1);

            cout << dp(0) << endl;
        }

        return 0; 
}
