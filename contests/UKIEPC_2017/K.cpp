#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) //cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;
typedef tuple<int,int,int> tr;

const int MAXN = 100+10;
int ans[MAXN], pre[MAXN];

int main() {
    fastio;

    //fill(pre, pre+MAXN, -1);

    int n;
    cin >> n;
    vector<tr> v;
    forn(i, n) {
        int w, l;
        cin >> w >> l;
        
        if (w < l)
            v.eb(w, l, i);
    }
    multiset<pii> act;
    int m;
    cin >> m;
    forn(i, m) {
        int t;
        cin >> t;
        act.insert(mp(0, -1));
        v.eb(t, -1, i); 
    }
    sort(all(v));

    bool can = true;
    for (tr t : v) {
        int w = get<0>(t), l = get<1>(t), ind = get<2>(t);

        auto it = act.lower_bound(mp(w, -1));
        //cerr << "busco para " << w << ' ' << ind << endl;

        if (l == -1) { // edificio
            if (it == act.end()) {
                can = false;
                break;
            }
            else {
                act.erase(it);
                //cerr << "sol de " << ind << " es " << it->second << endl;
                ans[ind] = it->second;
            }
        }
        else { // grua
            if (it != act.end() && l > it->first) {
                pre[ind] = it->second;
                //cerr << "pre de " << ind << " es " << it->second << endl;
                act.erase(it);
                //cerr << "inserto " << l << ' ' << ind << endl;
                act.insert(mp(l, ind));
            }
        }
    }

    if (can) {
        forn(i, m) {
            int act = ans[i];
            vi ans;
            while (act != -1) {
                ans.pb(act);
                act = pre[act];
            }
            reverse(all(ans));
            forn(i, si(ans)) {
                if (i) cout << ' ';
                cout << ans[i]+1;
            } 
            cout << endl;
        }
    }
    else 
        cout << "impossible" << endl;

    return 0;
}
