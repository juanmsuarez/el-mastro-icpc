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
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

vector<vi> ans;

inline void solvethree(int a, int b, int c) {
    ans.pb((vi){a, b, c});
    ans.pb((vi){a, b, c}); 
}
inline void solvefour(int a, int b, int c, int d) {
    ans.pb((vi){a, b, c, d});
    ans.pb((vi){a, b, d, c});
    ans.pb((vi){a, d, b, c});
}

void f(int n) {
    if (n == 3) solvethree(1, 2, 3);
    else if (n == 4) solvefour(1, 2, 3, 4);
    else {
        int i;
        for (i = n-2; i > 2; i -= 2) {
            ans.pb((vi){n-1, i-1, n, i});
            ans.pb((vi){n-1, i-1, n, i});
        }

        if (n%2 == 0) {
            ans.pb((vi){1, n-1, 2, n});
            ans.pb((vi){1, n, n-1});
            ans.pb((vi){2, n, n-1});
        } 
        else solvethree(1, n-1, n);

        f(n-2);
    }
}

int main() {
    fastio;

    int n;
    cin >> n;

    f(n);

    cout << si(ans) << endl;
    for (vi v : ans) {
        cout << si(v);
        for (int a : v) cout << ' ' << a;
        cout << endl;
    }

    return 0;
}
