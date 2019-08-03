#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = "  << a << endl
#else
    #define D(a)
    #define cerr false && cerr
#endif
#define forsn(i,s,n) for(int i = (int)s; i < (int)n;i++)
#define forn(i,n) forsn(i,0,n)
#define pb emplace_back
#define si(a) int(a.size())
using vi = vector<int>;
using ll = long long int;

const int N = 500;
int n, m, k; 
double memo[N][N];

double dp(int cups = 0, int failed = 0) {
    if (cups == n) return n - failed >= m && failed >= k;

    double &res = memo[cups][failed];
    if (res != -1) return res;

    res = 1./2*(dp(cups+1, failed) + dp(cups+1, failed+1));
    return res;
}

int main(){
    fill(memo[0], memo[N], -1);

    cin >> n >> m >> k;

    cout << fixed << setprecision(6) << dp() << endl;

    return 0;
}
