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

struct pto {
    int x, y, z;
    int& operator[](int p) {
        return (p == 0 ? x : (p == 1 ? y : z));
    }
    pto(int x=0, int y=0, int z=0) : x(x), y(y), z(z) {}
    bool operator == (const pto &o) {
        return x == o.x && y == o.y && z == o.z;
    }
    bool operator != (const pto &o) {
        return !(*this == o);
    }
};

typedef vector<pto> vp;

/*
void solve(vp &A, pto s, pto e) { // mueve sin mirar colisiones
    A.pb(s);
    //cerr << 2 << endl;
    forn(c, 3)
        while (s[c] != e[c]) {
            s[c] += e[c] > s[c] ? 1 : -1;
            A.pb(s);
        }
}

void solve(vp &A, vp &B, pto s, pto e) { // mueve mirando colisiones
    //cerr << 3 << endl;
    B.pb(s);
    forn(c, 3)
        while (s[c] != e[c]) {
            pto nxt = s;
            int dif = e[c] > s[c] ? 1 : -1;
            nxt[c] += dif;

            // desvio y vuelvo (pasa solo una vez)
            int pos = si(B)-1;
            //cerr << s.x << ' ' << s.y << ' ' << s.z << endl;
            ////cerr << nxt.x << ' ' << nxt.y << ' ' << nxt.z << endl;
            //cerr << A[pos].x << ' ' << A[pos].y << ' ' << A[pos].z << endl;
            //cerr << endl;
            if (pos+1 < si(A) && nxt == A[pos] && A[pos+1] == s) {
                A.insert(A.begin()+pos, A[pos]);
                s[(c+1)%3] += dif;
                B.pb(s);

                A.insert(A.begin()+pos, A[pos]);
                s = nxt;
                s[(c+1)%3] += dif;
                B.pb(s);
            }
            else if (pos+1 < si(A) && nxt == A[pos+1])
                nxt = s;

            s = nxt;
            B.pb(s);
        }
}
*/

pto nxt(pto s, pto e) {
    pto n = s;
    forn(i, 3) 
        if (abs(e[i] - n[i]) > 0) {
            n[i] += e[i] - n[i] > 0 ? 1 : -1;
            return n;
        }
    return e;
}

int main() {
    fastio;

    srand(time(0));

    pto s1, e1, s2, e2;
    int d1 = 0, d2 = 0;
    forn(i, 3) cin >> s1[i];
    forn(i, 3) cin >> e1[i];
    forn(i, 3) cin >> s2[i]; 
    forn(i, 3) cin >> e2[i];

    //cerr << 1 << endl;
    vp A, B;
    A.pb(s1); B.pb(s2);
    while (s1 != e1 || s2 != e2) {
        /*
        cerr << "act " << endl;
        cerr << s1.x << ' ' << s1.y << ' ' << s1.z << endl;
        cerr << s2.x << ' ' << s2.y << ' ' << s2.z << endl;
        */
        pto n1 = nxt(s1, e1), n2 = nxt(s2, e2);

        while (n1 == n2 || (s1 == n2 && s2 == n1)) {
            int d = rand()%3, c = (rand()%2 ? 1 : -1);
            
            //cerr << d << ' ' << c << endl;

            if (rand()%2) {
                n1 = s1;
                n1[d] += c;
                n2 = nxt(s2, e2);
            }
            else {
                n2 = s2;
                n2[d] += c;
                n1 = nxt(s1, e1);
            }

            cerr << n1.x << ' ' << n1.y << ' ' << n1.z << endl;
            cerr << n2.x << ' ' << n2.y << ' ' << n2.z << endl;
        }

        /*
        cerr << endl;
        cerr << "define " << endl;
        cerr << n1.x << ' ' << n1.y << ' ' << n1.z << endl;
        cerr << n2.x << ' ' << n2.y << ' ' << n2.z << endl;
        */

        s1 = n1;
        s2 = n2;
        A.pb(n1);
        B.pb(n2);
    }

    //cerr << 3 << endl;
    forn(i, si(A)) {
        cout << '(' << A[i].x << ' ' << A[i].y << ' ' << A[i].z << ") ";
        cout << '(' << B[i].x << ' ' << B[i].y << ' ' << B[i].z << ')' << endl;
    }

    return 0;
}
