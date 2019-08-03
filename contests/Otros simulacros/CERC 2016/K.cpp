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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N = 3e5+10;
bool a[N];
vi ans;

void change(int x) {
    ans.pb(x);
    a[x] ^= true;
    a[x+1] ^= true;
}

int cost(bool b[], bool pre) {
    int c = 0;
    if (pre != b[0]) c++;
    forn(i, 2) if (b[i] != b[i+1]) c++;
    return c;
}


int cost(bool b[]) {
    return cost(b, b[0]);
}

int main() {
	fastio;

    string s; cin >> s; int n = si(s);
    forn(i, n) a[i] = s[i] == '1'; 

    if (cost(a) < 1) change(0); 
    forsn(i, 3, n) {
        bool pre = a[i-1];
        if (cost(a+i, pre) < 2) {
            forn(j, 2) {
                bool win = false;
                a[i+j] ^= true, a[i+j+1] ^= true;
                if (cost(a+i, pre) >= 2) {
                    change(i+j);
                    win = true;
                }
                a[i+j] ^= true, a[i+j+1] ^= true;
                if (win) break;
            }
        }

        i += 2;
    }

    cout << si(ans) << endl;
    forn(i, si(ans)) {
        if (i) cout << ' ';
        cout << ans[i]+1;
    }
    cout << endl;

	return 0;
}
