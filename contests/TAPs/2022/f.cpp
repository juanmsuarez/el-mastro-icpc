#include <bits/stdc++.h>
using namespace std;

#define fastio cin.sync_with_stdio(0), cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)

#define all(a) (a).begin(),(a).end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int, int>;
using vi = vector<int>;
using ll = long long;

int main() {
    fastio;

    int n, c; cin >> n >> c;
    map<string, int> cnt;
    string ans;
    int mx = 0; 

    while (n--) {
        string s; cin >> s;

        forn(i, c) if (s[i] == '*') {
            forn(j, 26) {
                s[i] = char('a' + j);
                int cs = ++cnt[s];

                if (cs > mx) mx = cs, ans = s;
                else if (cs == mx && s < ans) ans = s;
            }

            break;
        }
    }

    cout << ans << ' ' << mx << endl;
    return 0;
}
