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

const int MAXN = 5e3+10;
bool cut[MAXN];
int memo[MAXN];

int mex(vi &v) {
    sort(all(v));
    int fi = 0;
    for (int a : v) {
        if (a > fi) break;
        fi = a+1;
    }
    return fi;
}

int dp(int n) {
    if (n <= 0) return 0;

    int &res = memo[n];
    if (res != -1) return res;

    vi v;
    forn(i, n) 
        v.pb(dp(i-1) ^ dp(n-(i+1)-1));

    return res = mex(v);
}

int main() {
    fastio;

    string s;
    cin >> s;
    int n = si(s);

    forsn(i, 1, n-1) 
        if (s[i-1] == s[i+1])
            cut[i] = true;

    vi juegos;
    int len = 0; 
    forn(i, n) {
        if (cut[i]) len++;
        else if (len > 0) {
            juegos.pb(len);
            len = 0;
        }
    }  
    if (len > 0) juegos.pb(len);

    fill(memo, memo+n, -1);

    int ans = 0;
    for (int j : juegos) {
        //cerr << '(' << j << ','<< dp(j) << ") ";
        ans ^= dp(j);
    }
    //cerr << endl;

    if (ans == 0) cout << "Second" << endl;
    else {
        cout << "First" << endl;

        int win, ind = 0, len = 0;
        forn(i, n) {
            if (cut[i]) {
                len++;
                if ((ans ^ dp(juegos[ind]) ^ dp(len-2) ^ dp(juegos[ind]-(len+1))) == 0) {
                    win = i;
                    break;
                }
            }
            else len = 0;

            if (i > 0 && !cut[i] && cut[i-1]) ind++;
        }
        cout << win+1 << endl;
    }

    return 0;
}
