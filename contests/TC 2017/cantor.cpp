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
#define endl '\n'
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

int totValidDigits, validDigits[15];
tint d, h, b;
string l;

vi toBase(tint n) {
    vi v;
    do {
        v.pb(n%b);
        n /= b;
    }
    while (n > 0);
    reverse(all(v));
    return v;
}

tint count(vi v) { // [0,x]
    tint inclusive = 1, exclusive = 1;

    tint ans = 0;
    dforsn(i, 0, si(v)) {
        inclusive = (l[v[i]] == 'S' ? inclusive : 0) + (v[i] ? validDigits[v[i]-1]*exclusive : 0);
        exclusive *= totValidDigits; //?

        if (l[0] == 'N' && i != 0) ans += exclusive;
    }
    ans += inclusive;

    return ans;
}

int main() {
        fastio;

        while (cin >> d >> h >> b >> l && d != -1) {
            vi lo = toBase(d-1), hi = toBase(h);            

            totValidDigits = 0;
            forn(i, si(l)) {
                validDigits[i] = (l[i] == 'S') + (i ? validDigits[i-1] : 0);
                totValidDigits += l[i] == 'S';
            }
            
            cout << count(hi) - count(lo) << endl;
        }

        return 0;
}
