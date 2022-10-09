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

const int N = 1e5;

int k, l, a[N], b[N];
multiset<int> s1, s2;
ll sum_k, sum_l;

void add(int i) {
    sum_k += a[i];
    int x = b[i];

    if (si(s2) == l) {
        auto f = s2.begin();

        if (x > *f) {
            int vf = *f;
            sum_l += x - vf;
            s2.erase(f);
            s1.insert(vf);
            s2.insert(x);
        }   
        else {
            s1.insert(x);
        }
    }
    else {
        sum_l += x;
        s2.insert(x);
    }
}

void del(int i) {
    sum_k -= a[i];
    int x = b[i];

    if (x >= *(s2.begin())) {
        auto p = s2.find(x);
        sum_l -= *p;
        s2.erase(p);
        
        if (l != k) {
            auto q = prev(s1.end());
            s2.insert(*q);
            sum_l += *q;
            s1.erase(q);
        }
    }
    else {
        auto p = s1.find(x);
        s1.erase(p);
    }
}

int main() {
    fastio;

    int n; cin >> n;
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    cin >> k >> l;

    forn(i, k) add(i);

    ll ans = sum_k + sum_l;

    if (k < n) {
        forn(i, k) {
            del(k-i-1), add(n-i-1);
            ans = max(ans, sum_k + sum_l);
        }
    }

    cout << ans << endl;
    return 0;
}
