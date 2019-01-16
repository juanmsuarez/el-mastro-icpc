#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) ((int)(a).size())
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(c) (c).begin(), (c).end()
#define D(a) //cerr << #a << "=" << a << endl;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAXN = (1<<20)+1;
const tint neutro = 0;
typedef tint tipo;

struct Fenwick{
	static const int sz=MAXN;
	tipo t[sz];
	void init() {
		forn(i, sz) t[i] = neutro;
	}
	void set(int p){//valid with p in [1, sz), O(lgn)
		for(int i=p; i<sz; i+=(i&-i)) t[i]++; }
	tipo sum(int p){//cumulative sum in [1, p], O(lgn)
		tipo s=0;
		for(int i=p; i; i-=(i&-i)) s+=t[i];
		return s;
	}
	tipo sum(int a, int b){return sum(b)-sum(a-1);}

	int getind(tipo v) {
		int x = 0;
		for (int d = 1 << (31-__builtin_clz(sz)); d; d >>= 1)
			if (t[x|d] < v) {
				x |= d;
				v -= t[x];
			}
		return x + 1; 
	}
} rmq;

struct point{
	tint x,y;
	int cx,cy;
	point(){}
	point(tint x,tint y, int cx, int cy):x(x),y(y),cx(cx),cy(cy){}
	bool operator <(const point& p)const{
		return (x==p.x?y<p.y:x<p.x);
	}
};

vector<point>seq;
tint realcol[MAXN];
int m, n;

tint solve(){
	tint res = -1;
	sort(all(seq));
	rmq.init();

	forn(i, n){
		while (i<si(seq)-1 && seq[i].cx==seq[i+1].cx) {
			rmq.set(seq[i].cy);
			i++;
		}
        rmq.set(seq[i].cy);
		if (i+1 < n/2) continue;
		
		int mayorIgual = rmq.getind(si(seq)/2);

        tint area = (seq[i].x+1)*(realcol[mayorIgual]+1);
		if (rmq.sum(1, mayorIgual) == si(seq)/2)
            res = (res == -1 ? area : min(res, area));
	}

    return res;
}

inline void rotate() {
	forn(i, n) {
		seq[i] = (point){seq[i].y, m-seq[i].x-1, seq[i].cy, n-seq[i].cx+1};
		realcol[seq[i].cy] = seq[i].y;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> m >> n){
        seq = vector<point>(n);
        forn(i,n)
            cin >> seq[i].x >> seq[i].y;

		if(n%2) cout << -1 << endl;
		else {
			// comprimo y
            sort(all(seq), [](point a,point b){
				return (a.y==b.y?a.x<b.x:a.y<b.y);
			});
            seq[0].cy=1;
			realcol[seq[0].cy]=seq[0].y;
            forsn(i,1,n){
                seq[i].cy=(seq[i].y==seq[i-1].y ? seq[i-1].cy : seq[i-1].cy+1);
                realcol[seq[i].cy]=seq[i].y;
            }

			// comprimo x
            sort(all(seq));
            seq[0].cx=1;
            forsn(i,1,n) seq[i].cx=(seq[i].x==seq[i-1].x ? seq[i-1].cx : seq[i-1].cx+1);

			tint res = -1;
			forn(_, 4) {
				tint sol = solve();
				if (res == -1) res = sol;
				else if (sol != -1) res = min(res, sol);
				rotate();
			}
			cout << res <<endl;
		}
	}

	return 0;
}
