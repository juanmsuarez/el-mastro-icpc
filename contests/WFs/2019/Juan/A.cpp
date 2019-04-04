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

struct trio {
    int p,h,i;
    trio(int p=0,int h=0,int i=0):p(p),h(h),i(i){}
    bool operator < (const trio &o) const {
        return p < o.p;
    }
};

const int N = 5e5;
trio a[2][N];
int res[2][N];

int main() {
    fastio;
    
    int n; cin >> n;

    forn(i, 2) {
        forn(j, n) a[i][j].i = j+1;
        forn(j, n) cin >> a[i][j].p;
        forn(j, n) cin >> a[i][j].h;
        sort(a[i], a[i]+n);
    }

    bool ok = true;
    set<pii> s[2];
    int ind[2] = {0, 0}, sgn[2] = {1, -1}, k = 0;
    
    while (k < n) {
        forn(i, 2) 
            if (s[i].empty()) {
                int &j = ind[i], start = j;
                while (j < n && a[i][start].p == a[i][j].p) {
                    s[i].insert({sgn[i]*a[i][j].h, a[i][j].i});
                    j++;
                }
            }

        if (!s[0].empty() && !s[1].empty()) {
            int i1 = si(s[0]) < si(s[1]) ? 0 : 1, i2 = 1 - i1;
            auto it = s[i2].upper_bound({-s[i1].begin()->fst, n}); 
            if (it == s[i2].end()) { ok = false; break; }
            res[i1][k] = s[i1].begin()->snd; res[i2][k] = it->snd;
            s[i1].erase(*s[i1].begin()); s[i2].erase(it);
        }

        k++;
    }   

    if (!ok) cout << "impossible" << endl;
    else forn(i, 2) forn(j, n) cout << res[i][j] << " \n"[j==n-1];

    return 0;
}
