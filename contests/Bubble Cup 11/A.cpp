#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace  __gnu_pbds;

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

typedef tree<pii,null_type,less<pii>,//key,mapped type, comparator
    rb_tree_tag,tree_order_statistics_node_update> sset;

struct robot {
    int x, r, q, id;
    robot(int x=0, int r=0, int q=0, int id=0) : x(x), r(r), q(q), id(id) {}
};

struct event {
    robot r; bool open;
    event(robot r, bool open) : r(r), open(open) {}
    int id() const { return open ? r.x : r.x+r.r+1; }
    bool operator < (const event &o) const { return id() < o.id() || (id() == o.id() && !open && o.open); }
};

const int MAXN = 1e5+10;
sset s[MAXN];
vi iqs;

int main() {
	fastio;
	
    int n, k; cin >> n >> k;
    vector<event> events;
    forn(i, n) {
        robot r; cin >> r.x >> r.r >> r.q; r.id = i;
        events.pb((event){r, true}); events.pb((event){r, false});
        iqs.pb(r.q);
    }

    sort(all(iqs)); iqs.erase(unique(all(iqs)), iqs.end());
    for (event &e : events) e.r.q = lower_bound(all(iqs), e.r.q) - iqs.begin();

    sort(all(events));

    ll ans = 0;
    for (event &e : events) {
        robot &r = e.r;
        if (e.open) {
            int start = lower_bound(all(iqs), iqs[r.q] - k) - iqs.begin(), 
                end = upper_bound(all(iqs), iqs[r.q]+k) - iqs.begin();

            forsn(iq, start, end)
                ans += si(s[iq]) - s[iq].order_of_key({r.x-r.r, -1});

            s[r.q].insert({r.x, r.id});
        }
        else {
            s[r.q].erase({r.x, r.id});
        }
    }

    cout << ans << endl;
	
	return 0;
}
