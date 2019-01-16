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

int main() {
    fastio;

    int n;
    cin >> n;

    if (n == 1) cout << "HM" << endl;
    else {
        int h = 0, m = 0;
        char last;
        forn(i, n-1) {
            cin >> last;

            if (last == 'H') h++;
            else m++;
        }

        char win;
        if (h > m) win = 'H';
        else if (m > h) win = 'M';
        else win = last == 'H' ? 'M' : 'H';
        cout << win << endl;
    }

    return 0;
}
