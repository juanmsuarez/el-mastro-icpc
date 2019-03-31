#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

struct card {
    int dr, dg, db, id, ind;
    card(int dr, int dg, int db, int id, int ind) : dr(dr), dg(dg), db(db), 
                                                    ind(ind), id(id) {}

    int &operator[] (int ind) {
        return (ind == 0 ? dr : (ind == 1 ? dg : db));
    }

    bool operator < (const card &o) const {
        return (dr+dg+db == o.dr+o.dg+o.db && id > o.id) ||
            dr+dg+db < o.dr+o.dg+o.db;
    }
};

ostream& operator << (ostream &strm, const card &c) {
    strm << c.dr << ' ' << c.dg << ' ' << c.db << ' ' << c.id << ' ' << c.ind;
    return strm;
}

const int MAXN = 1e5+10;
int pos[MAXN][3], nxt[MAXN][3], pre[MAXN][3], id[MAXN];

inline int dif(int i, int c) {
    if (pos[nxt[i][c]][c] == pos[i][c] || pos[pre[i][c]][c] == pos[i][c]) return 0;

    int d = (pos[nxt[i][c]][c] - pos[pre[i][c]][c] + 360)%360;

    return d == 0 ? 360 : d;
}

inline card getCard(int i) {
    return {dif(i, 0), dif(i, 1), dif(i, 2), id[i], i};
}

int main() {
    fastio;

    int n;
    cin >> n;

    forn(i, n) {
        forn(j, 3) cin >> pos[i][j];
        cin >> id[i];
    }

    forn(c, 3) {
        vector<pii> oa;
        forn(j, n) oa.eb(pos[j][c], j);
        sort(all(oa));

        int pa, pi;
        tie(pa, pi) = oa.back();
        for (auto [a,i] : oa) {
            nxt[pi][c] = i;
            pre[i][c] = pi;

            pi = i; pa = a;
        }
    }

    set<card> s;
    forn(i, n) 
        s.insert(getCard(i));

    while (si(s) > 2) {
        card c = *s.begin();
        s.erase(c);

        //cerr << c << endl;
        cout << c.id << endl;

        forn(color, 3) {
            card b = getCard(pre[c.ind][color]), 
                 d = getCard(nxt[c.ind][color]);

            //cerr << "pre " << ' ' << b << endl;
            s.erase(b);
            //cerr << "nxt " << ' ' << d << endl;
            s.erase(d);

            nxt[b.ind][color] = d.ind;
            pre[d.ind][color] = b.ind;

            //cerr << "pre " << ' ' << b << endl;
            s.insert(getCard(b.ind));
            //cerr << "nxt " << ' ' << d << endl;
            s.insert(getCard(d.ind));
            //cerr << endl;
        }
    }

    cout << s.begin()->id << endl;
    s.erase(s.begin());
    if (!s.empty()) cout << s.begin()->id << endl;

    return 0;
}
