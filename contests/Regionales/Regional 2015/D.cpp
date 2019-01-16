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
typedef long long int ll;

int main() {
    fastio;

    int n, m;
    while (cin >> n >> m) {
        int ans = 0;

        while (m--) {
            int b, d;
            cin >> b >> d;
            forn(i, n-1) {
                int a;
                cin >> a;
                b -= a;
            } 
            b -= d;

            if (b >= 0) {
                if (b+d >= 10000 && 10000 > d)
                    ans += 10000 - d;
                else if (b+d >= 1000 && 1000 > d)
                    ans += 1000 - d;
                else if (b+d >= 100 && 100 > d)
                    ans += 100 - d;
                else if (b+d >= 10 && 10 > d)
                    ans += 10 - d;
            }
            else {
                if (b+d-1000 >= 0)
                    ans += 1000;
                else if (b+d-100 >= 0)
                    ans += 100;
                else if (b+d-10 >= 0)
                    ans += 10;
                else if (b+d-1 >= 0)
                    ans += 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
