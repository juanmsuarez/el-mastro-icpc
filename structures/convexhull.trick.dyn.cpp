#include <bits/stdc++.h>
using namespace std;
#define forsn(i, a, b) for(int i=a; i<(b); i++)
#define forn(i, n) forsn(i, 0, n)
#define foratint(it, v) for(auto it=v.begin(); it!=v.end(); ++it)
#define si(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
typedef long long tint;
typedef pair<int,int> ii;
#define EPS 1e-9
#define tipo int

const tint is_query = -(1LL<<62);
struct Line {
    tint m, b;
    mutable multiset<Line>::iterator it;
    const Line *succ(multiset<Line>::iterator it) const;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line *s=succ(it);
        if(!s) return 0;
        tint x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line>{ // will maintain upper hull for maximum
    bool bad(iterator y) {
        iterator z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        iterator x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
    }
    iterator next(iterator y){return ++y;} 
    iterator prev(iterator y){return --y;} 
    void insert_line(tint m, tint b) {
        iterator y = insert((Line) { m, b });
        y->it=y;
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    tint eval(tint x) {
        Line l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
}h;
const Line *Line::succ(multiset<Line>::iterator it) const{
    return (++it==h.end()? NULL : &*it);}

//PROBLEMA F ACMICPC WORLD FINALS 2011
struct machine{
	tint d;
	tint p;
	tint r;
	tint g;	
} m[100010];

bool cmp (machine a, machine b){
	return a.d < b.d;
}
int main(){
	//~ freopen("f.in", "r", stdin);
	tint n, c,d, t = 1;
	while(cin >> n >> c >> d, n){
		h=HullDynamic();
		forn (i,n)
			cin >> m[i].d >> m[i].p >> m[i].r >> m[i].g;			
		sort (m, m+n, cmp);
		
		
		h.insert_line(0,c);
		forn (i,n){
			tint money = h.eval(m[i].d);
			if (m[i].p <= money)
				h.insert_line (m[i].g, money - m[i].p + m[i].r - m[i].g * (m[i].d + 1)); 
		}
		
		cout << "Case " << t++ << ": " << h.eval (d+1) << endl;

	}
	return 0;
}
