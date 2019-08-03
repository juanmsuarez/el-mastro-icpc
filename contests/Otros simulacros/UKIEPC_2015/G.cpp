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

const int MAXD = 10, MAXU = 1200+10, MAXM = 1000+10;
string name[MAXD];
int cant[MAXD], cost[MAXD], memo[MAXD][MAXU][MAXM];

bool dp(int drink, int units, int money) {
    if (units < 0 || money < 0) return false;
    if (units == 0 && money == 0) return true;
    if (drink == -1) return false;

    //cerr << drink << ' ' << units << ' ' << money << endl;

    int &ans = memo[drink][units][money];
    if (ans != -1) return ans;
    ans = false;

    ans |= dp(drink-1, units, money);
    ans |= dp(drink, units-cant[drink], money-cost[drink]);

    return ans;
}

int main() {
    fastio;

    double mm, uu;
    int m, u, d;
    cin >> mm >> uu >> d;
    m = mm*100; u = uu*10*6;

    forn(i, d) {
        char _;
        int str, sz;
        double c;

        cin >> name[i] >> str >> _ >> _ >> sz >> c;
        cant[i] = str*10*6/sz;
        cost[i] = c*100;
    } 

    fill(memo[0][0], memo[MAXD][0], -1);
    //cerr << 1 << endl;
    bool can = dp(d-1, u, m);
    //cerr << 1 << endl;

    if (!can) cout << "IMPOSSIBLE" << endl;
    else {
        int drink = d-1, units = u, money = m, cnt = 0; 

        while (units > 0 || money > 0) {
            //cerr << drink << ' '  << units << ' ' << money << endl;
            if (drink > 0 && memo[drink-1][units][money] == 1) {
                if (cnt > 0) {
                    cout << name[drink] << ' ' << cnt << endl;
                    cnt = 0;
                }

                drink = drink-1; 
            }
            else {
                units -= cant[drink];
                money -= cost[drink];
                cnt++;
            }
        }
        if (cnt > 0) 
            cout << name[drink] << ' ' << cnt << endl;
    }

    return 0;
}
