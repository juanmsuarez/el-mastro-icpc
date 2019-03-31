#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define eb emplace_back
#define pb push_back
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

    int n, k;
    cin >> n >> k;

    set<int> seen, S, T;
    forn(i, n) {
        int num = 0;
        char c;
        forn(j, k) {
            cin >> c;
            num |= (c-'0') << j; 
        }
        S.insert(num);
    }

    while (si(seen) + si(S) < (1<<k)) {
        for (int num : S)
            seen.insert(num);     

        for (int num : S)
            forn(i, k) {
                int nnum = num ^ (1<<i);

                if (seen.count(nnum) == 0)
                    T.insert(nnum);
            }

        S = T;
        T.clear();
    }

    int ans = *S.begin();
    forn(i, k) cout << (ans & (1<<i) ? 1 : 0);
    cout << endl;

    return 0;
}
