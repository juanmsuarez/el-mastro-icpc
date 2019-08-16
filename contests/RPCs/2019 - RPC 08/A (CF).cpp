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

const int INF = 1e8;

struct Frog {
    int l, w, h;
    Frog(int _l = 0, int _w = 0, int _h = 0) : l(_l), w(_w), h(_h) {}

    bool operator < (const Frog &o) const {
        return w < o.w;
    }
};

int main() {
	fastio;
	
    int n, d; cin >> n >> d;
    vector<Frog> frogs(n); 
    for (Frog &frog : frogs) cin >> frog.l >> frog.w >> frog.h;

    sort(all(frogs)); reverse(all(frogs));

    int escaped = 0;
    int max_weight = frogs.front().w;
    vi max_height(max_weight + 1);
    for (auto [l, w, h] : frogs) {
        if (max_height[w] + l > d) escaped++;
        
        forsn(weight, 1, w) {
            int height = h;
            if (weight + w <= max_weight) height += max_height[weight + w];

            max_height[weight] = max(max_height[weight], min(height, INF));
        }
    } 

    cout << escaped << endl;
	
	return 0;
}
