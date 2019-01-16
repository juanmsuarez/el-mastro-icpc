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
    #define cerr  false && cerr
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN = 1e4+10;
int a[MAXN], n;

bool can(int k) {
    int sum = 0;
    forn(i, n) sum += min(a[i], 2*k);
    return sum >= 3*k;
}

int main() {
    fastio;

    int sum = 0;
    while (cin >> n) {
        forn(i, n) {
            cin >> a[i];
            sum += a[i];
        }
        if (n < 3) cout << 0 << endl;
        else {
            int lo = 0, hi = sum+1;
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;

                if (can(mid)) lo = mid;
                else hi = mid;
            }

            cout << lo << endl;
        }
    }

    return 0;
}
