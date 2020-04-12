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

int n;
int rev(int pos) { return n - pos - 1; }

void build(vi &hs, set<int> &seq) {
    int pre = -1;
    forn(i, n) if (hs[i] > pre) pre = hs[i], seq.insert(i); 
}

void update(vi &hs, set<int> &seq, int pos, int nh) {
    auto it = seq.lower_bound(pos);

    while (it != seq.end() && hs[*it] <= nh) {
        auto nit = next(it);
        seq.erase(it);
        it = nit;
    }

    if (it == seq.begin() || hs[*prev(it)] < nh) seq.insert(pos);
}

int query(set<int> &seq, int pos, bool going_up) {
    auto next_it = seq.lower_bound(pos);
    if (going_up && *next_it == pos && next(next_it) != seq.end()) next_it++;
    return *next_it;
}

int main() {
	fastio;
	
    int m; cin >> n >> m;
    vi hs(n); for (int &h : hs) cin >> h;

    vi rhs = hs; reverse(all(rhs));

    set<int> inc; build(hs, inc);
    set<int> dec; build(rhs, dec);
    int mid = *inc.rbegin();

    while (m--) {
        char type; cin >> type;
        int pos; cin >> pos; pos--;

        if (type == 'U') {
            int nh; cin >> nh;

            update(hs, inc, pos, nh);
            hs[pos] = nh;

            update(rhs, dec, rev(pos), nh);
            rhs[rev(pos)] = nh;

            mid = *inc.rbegin();
        }
        else {
            bool left_pos = pos <= mid; 
            bool right_jump = type == 'R';

            int ans;
            if (left_pos) ans = query(inc, pos, right_jump);
            else ans = rev(query(dec, rev(pos), !right_jump));

            cout << ans + 1 << endl;
        }
    }
	
	return 0;
}
