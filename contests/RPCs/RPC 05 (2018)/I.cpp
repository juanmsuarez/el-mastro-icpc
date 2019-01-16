#include<map>
#include<set>
#include<iostream>
#include<vector>

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

    int t;
    cin >> t;
    while (t--) {
        map<int, int> u;
        map<int, int, greater<int>> d;

        int n;
        cin >> n;
        forn(i, n) {
            int a;
            cin >> a;
            u[a]++;
            d[a]++;
        }

        int q;
        cin >> q;
        while (q--) {
            int p, y;
            cin >> p >> y;

            if (p == 1) {
                auto it1 = d.upper_bound(y);
                cout << (it1 == d.end() ? -1 : it1->first) << ' ';
                auto it2 = u.upper_bound(y);
                cout << (it2 == u.end() ? 100001 : it2->first) << endl;
            }
            else if (p == 2) {
                u[y]++;
                d[y]++;
            }
            else {
                u[y]--;
                d[y]--;

                if (u[y] == 0) {
                    u.erase(y);
                    d.erase(y);
                }
            }
        }
    }

    return 0;
}
