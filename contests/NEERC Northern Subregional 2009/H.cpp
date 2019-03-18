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
    freopen("homo.in", "r", stdin);
    freopen("homo.out", "w", stdout);
	fastio;
	
    int n; cin >> n;

    int groups = 0, groupsmany = 0;
    map<int,int> m;
    while (n--) {
        string op; int x; cin >> op >> x;
        if (op[0] == 'i') {
            if (m[x] == 0) groups++;
            else if (m[x] == 1) groupsmany++;

            m[x]++;
        }
        else {
            if (m[x] != 0) {
                m[x]--;

                if (m[x] == 0) groups--;
                else if (m[x] == 1) groupsmany--;
            }
        }

        if (groups > 1 && groupsmany > 0) cout << "both" << endl;
        else if (groups > 1) cout << "hetero" << endl;
        else if (groupsmany > 0) cout << "homo" << endl;
        else cout << "neither" << endl;
    }
	
	return 0;
}
