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

const int MAXN = 1e5+10;
int p[MAXN];

int main() {
    fastio;

    int n, d, a, b;
    cin >> n >> d >> a >> b;
    forn(i, n) cin >> p[i];

    int inc = 0, dec = 0, shares = 0;
    forsn(i, 1, n) {
        int cant;
        if (p[i] > p[i-1]) {
            dec = 0; inc++; 

            cant = min(d/p[i], inc*a);

            shares += cant;
            d -= cant*p[i]; 
        }
        else if (p[i] < p[i-1]) {
            inc = 0; dec++;

            cant = min(shares, dec*b);

            shares -= cant;
            d += p[i]*cant;
        }
    }

    cout << d << ' ' << shares << endl;

    return 0;
}
