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

const int N = 1e3;
double memo[N][N];

int target;

double p(int n, int m) {
    return 1. * n / m;
}

double dp(int less, int greater) {
    if (less < 0 || greater < 0) return 0;
    int total = less + greater + 1;
    if (total < target) return 0;
    if (total == 1) return 1;

    double &res = memo[less][greater];
    if (res != -1) return res;
    res = 0;

    res += p(less, total) * p(less - 1, total - 1)  * dp(less - 1, greater);

    res += 2 * p(less, total) * p(1, total - 1) * (total == target);

    res += 2 * p(less, total) * p(greater, total - 1) * dp(less, greater - 1);

    res += p(greater, total) * p(greater - 1, total - 1) * dp(less, greater - 1);

    res += 2 * p(1, total) * p(greater, total - 1) * dp(less, greater - 1);

    return res;
}

int main() {
	fastio;

    fill(memo[0], memo[N], -1);
	
    int teams, start; cin >> teams >> start >> target;     

    double ans = dp(start - 1, teams - start);
    cout << fixed << setprecision(4) << ans << endl;
	
	return 0;
}
