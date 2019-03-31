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
typedef vector<pii> vii;

const int N = 3e3+10, INF = 1e9;
bool seen[N];
pii v[N];

int main() {
	fastio;
	
    int n; cin >> n; n *= 4;
    forn(i, n) cin >> v[i].fst >> v[i].snd; 

    sort(v, v+n);

    ll area = 0;
    forn(i, n) {
        if (seen[i]) continue;
        seen[i] = true;

        cerr << "miro " << v[i].fst << ' ' << v[i].snd << endl;

        pii up = {INF, INF}, right = {INF, INF};
        forn(j, n) {
            if (seen[j]) continue;

            if (v[i].fst == v[j].fst) up = min(up, v[j]);
            if (v[i].snd == v[j].snd) right = min(right, v[j]);
        }
        
        cerr << "matchea con " << up.fst << ' ' << up.snd << endl;
        cerr << "y " << right.fst << ' ' << right.snd << endl;

        forn(j, n) 
            if (v[j] == up || v[j] == right || v[j] == mp(up.snd, right.fst))
                seen[j] = true;

        area += (ll)(up.snd - v[i].snd)*(right.fst - v[i].fst);
    }
    cout << area << endl;
        
	return 0;
}
