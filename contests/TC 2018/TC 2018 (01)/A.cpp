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

void go(vi &v, int s) {
    for (int &a : v) {
        int k = min(9-a, s);
        s -= k;
        a += k;
    }
}

void print(vi &v) {
    for (int a : v) cout << a;
}

int main() {
    fastio;

    int m, s;
    cin >> m >> s;

    if ((s == 0 && m > 1) || 9*m < s) cout << "-1 -1" << endl;
    else {
        vi mn(m, 0), mx(m, 0);
        
        if (s > 0) mn[0]++, mx[0]++, s--;

        reverse(all(mn));
        go(mn, s);
        reverse(all(mn));
        go(mx, s);

        print(mn);
        cout << ' ';
        print(mx);
        cout << endl;
    }

    return 0;
}
