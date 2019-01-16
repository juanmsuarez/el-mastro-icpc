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

int main() {
    fastio;

    int nc;
    cin >> nc;
    
    while (nc--) {
        int n;
        cin >> n;

        priority_queue<tint, vector<tint>, greater<tint>> pq;
        forn(i, n) {
            int a;
            cin >> a;
            pq.push(a);
        }

        tint ans = 0;
        while (pq.size() > 1) {
            tint a = pq.top(); pq.pop();
            tint b = pq.top(); pq.pop();

            ans += a+b;
            pq.push(a+b);
        }

        cout << ans << endl;
    }

    return 0;
}
