#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forsn(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(a) a.begin(),a.end()
#define si(a) ((int)(a).size())
#define pb emplace_back
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fst first
#define snd second
using vi = vector<int>;
using ll = long long;
using pii = pair<int,int>;

int main(){
    fastio;

    int t; cin >> t;
    while (t--) {
        int m, k; cin >> m >> k;
        vi pages(m); for (int &p : pages) cin >> p;

        // binary
        auto can = [&](ll mx) {
            int scriber = k-1, book = m-1;

            while (book >= 0) {
                if (scriber == -1) return false;

                ll acum = 0;
                while (book >= scriber && acum + pages[book] <= mx) {
                    acum += pages[book];
                    book--;
                }
                if (acum == 0) return false;

                scriber--;
            }

            return true;
        };
        
        ll lo = 1, hi = 1e18;
        while (hi - lo > 1) {
            ll mid = (lo + hi) / 2;
            if (can(mid)) hi = mid;
            else lo = mid;
        }

        // build
        vi inds;
        int scriber = k-1, book = m-1;
        while (book >= 0) {
            ll acum = 0;
            while (book >= scriber && acum + pages[book] <= hi) {
                acum += pages[book];
                book--;
            } 
            inds.pb(book+1);
            scriber--;
        }

        // print
        inds.pop_back();
        forn(i, m) {
            if (inds.back() == i) cout << "/ ", inds.pop_back();
            cout << pages[i] << " \n"[i==m-1];
        }
    }

    return 0;
}
