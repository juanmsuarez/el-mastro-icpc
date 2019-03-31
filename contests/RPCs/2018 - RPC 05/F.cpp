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

const int MAXN = 1e5+10, MAXT = 60+10;
int s[MAXN][MAXT];

int main() {
    fastio;

    int nc;
    cin >> nc;

    while (nc--) {
        int n;
        cin >> n;

        forn(i, n) {
            int a;
            cin >> a;

            forsn(t, 1, 60+1)
                s[i+1][t] = s[i][t];
            s[i+1][a]++;
        }

        int q;
        cin >> q;
        while (q--) {
            int a, b;
            cin >> a >> b;
            a--;
           
            int cnt = 0;
            forsn(t, 1, 60+1) {
                int sum = s[b][t] - s[a][t];
                if (sum%2==1) cnt++; 
            }
            cout << cnt << endl;
        }
    }

    return 0;
}
