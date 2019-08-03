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
#define D(a) cerr << #a << "=" << a << endl;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

struct node{
	int x, y, t;
	node(int _x = 0, int _y = 0, int _t = 0){
		x = _x;
		y = _y;
		t = _t;
	}
};

node a[250000+10], b, e;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int nc;
	cin >> nc;
	while (nc--) {
		
		int d = INT_MAX, n, x = 0, y = 0, t; 
		cin >> n;
		n++;
		
		a[0] = node(0,0,0);
		forsn(i,1,n){
			char o; cin >> o;
			if(o == 'S') y--;
			else if(o == 'N') y++;
			else if(o == 'W') x--;
			else x++;
			a[i] = node(x,y,i);
		}
		
		sort(a,a+n,[] (node &a, node &b) {
			return a.x < b.x || (a.x == b.x && a.y < b.y);
		});
		
		forn(i,n-1)
			if(a[i].x == a[i+1].x && abs(a[i].t - a[i+1].t) > 1){
				//cerr << "Miro "<< a[i].t << " y " << a[i+1].t << endl;
				 int cd = abs(a[i].y - a[i+1].y);
				 node *_b, *_e;
				 if(a[i].t < a[i+1].t){
					_b = &a[i];
					_e = &a[i+1];
				 } else {
					_b = &a[i+1];
					_e = &a[i];
				 }
				 
				 if(cd < d || (cd == d && (_b->t < t || (_b->t == t && _e->t > e.t) ) ) ){
					d = cd;
					b = *_b;
					e = *_e;
					t = b.t;
				 } 
			}
			
		
		sort(a,a+n,[] (node &a, node &b) {
			return a.y < b.y || (a.y == b.y && a.x < b.x);
		});
		
		forn(i,n-1)
			if(a[i].y == a[i+1].y && abs(a[i].t - a[i+1].t) > 1){
				 int cd = abs(a[i].x - a[i+1].x);
				 node *_b, *_e;
				 if(a[i].t < a[i+1].t){
					_b = &a[i];
					_e = &a[i+1];
				 } else {
					_b = &a[i+1];
					_e = &a[i];
				 }
				 
				 if(cd < d || (cd == d && (_b->t < t || (_b->t == t && _e->t > e.t) ) ) ){
					d = cd;
					b = *_b;
					e = *_e;
					t = b.t;
				 } 
			}
		
		char dir;
		if (b.x == e.x){
			if(b.y > e.y) dir = 'S';
			else dir = 'N';
		} else{
			if(b.x > e.x) dir = 'W';
			else dir = 'E';
		}
		
		cout << d << ' ' << b.t << ' ' << e.t << ' ' <<dir << endl;
		cout << endl;
	}
	return 0;
}
