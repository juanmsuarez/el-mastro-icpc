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

    int l, r;
    cin >> l >> r;

    if (l == 0 && r == 0) cout << "Not a moose" << endl;
    else if (l == r) cout << "Even " << l+r << endl;
    else cout << "Odd " << 2*max(l,r) << endl;

    return 0;
}
