#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int main() {
	fastio;
	
    int m; cin >> m;
    int x = m+1, n = x+1;
    ll sum1 = m, sum2 = n;

    while (sum1 != sum2) {
        while (sum1 < sum2) {
            sum1 += x;
            x++;
            sum2 -= x;
            if (x == n) n++, sum2 += n;
        }
        while (sum2 < sum1) n++, sum2 += n;
    }

    cout << m << ' ' << x << ' ' << n << endl;
	
	return 0;
}
