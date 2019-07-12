#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i=int(s);i<(int)n;i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=(int)s;i--)
#define dforn(i,n) dforsn(i,0,n)

#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second 
#define fst first
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int w, h;
set<int> cuts[2]; // x = 0, y = 1
multiset<int> interLength[2];

void init() {
    cuts[0].insert(0); cuts[0].insert(w);
    cuts[1].insert(0); cuts[1].insert(h);

    interLength[0].insert(w);
    interLength[1].insert(h);
}

void update(int coord, int pos) {
    auto r = cuts[coord].lower_bound(pos), l = r; l--;
    int lpos = *l, rpos = *r; 

    int length = rpos - lpos;
    interLength[coord].erase(interLength[coord].lower_bound(length));

    int nlength1 = pos - lpos, nlength2 = rpos - pos;
    interLength[coord].insert(nlength1);
    interLength[coord].insert(nlength2);

    cuts[coord].insert(pos);
}

ll query() {
    int maxX = *interLength[0].rbegin(), 
        maxY = *interLength[1].rbegin();
    return (ll)maxX*maxY;
}

int main(){
    fastio; 
    int n; cin >> w >> h >> n; 
    init(); 
    while (n--) {
        char c; int pos; cin >> c >> pos;
        int coord = c == 'V' ? 0 : 1;
        update(coord, pos); 
        cout << query() << endl;
    }

    return 0;
}
