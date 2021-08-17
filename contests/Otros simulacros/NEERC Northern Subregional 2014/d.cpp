#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl
#else 
    #define D(a) 8 
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define all(a) (a).begin(),(a).end()
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const ll INF = 2e18;
const int N = 5e3, D = 19;

ll best[N+1], total_sum, ten[D];
int target, cnt;

void gen(ll cur = 0, int sum = 0, int digits = 0) {
    if (sum == target) {
        cnt++;
        total_sum += cur;
        best[cnt] = min(best[cnt], total_sum);
        return;
    }

    if (digits < D) dforn(d, 10) 
        if (cnt <= N && sum + d <= target)
            gen(d * ten[digits] + cur, sum + d, digits + 1);
}

int main() {
    fastio;

    ten[0] = 1;
    forsn(i, 1, D) ten[i] = ten[i-1] * 10;

    forn(i, N+1) best[i] = INF;
    forsn(i, 1, 200) {
        total_sum = cnt = 0;
        target = i;
        gen();
    } 

    ll bk[N+1];
    forn(i, N+1) bk[i] = best[i];

    forn(i, N+1) best[i] = INF;
    forsn(i, 1, 250) {
        total_sum = cnt = 0;
        target = i;
        gen();
    } 

    forsn(i, 1, 30) cout << i <<' ' << best[i] << endl;

    forn(i, N+1) if (bk[i] != best[i]) {
        cerr << "Move bound\n";
        break;
    }  
    
    return 0;
}
