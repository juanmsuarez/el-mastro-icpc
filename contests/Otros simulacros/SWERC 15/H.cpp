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
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

tint lo, hi, ans = 0;

void go(int ind, int A, int B, tint num) {
    while (ind < 63) {
        forn(_, B) 
            ind++;

        forn(_, A) {
            num += (1LL<<ind);
            ind++;
        }

        if (ind <= 63 && num >= lo && num <= hi) {
            ans++;
        }
    }
}

int main() {
    fastio;

    cin >> lo >> hi;

    forsn(A, 1, 64) {
        // solo a
        tint x = (1LL<<A)-1;
        if (x >= lo && x <= hi) ans++;

        forsn(B, 1, 64) {
            tint startA = x, startB = 0;

            go(A, A, B, startA);
            go(0, A, B, startB);
        }
    }

    cout << ans << endl;

    return 0;
}
