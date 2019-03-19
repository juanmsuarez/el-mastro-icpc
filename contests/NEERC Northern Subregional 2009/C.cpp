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

const int MAXH=20000+10;
    
vector<pii> paren[MAXH];

int main() {
	fastio;
    freopen("circles.in","r",stdin);
    freopen("circles.out","w",stdout);
	
	ll w,h,n;
    cin >> w >> h >>n;

    forn(i,n){
        ll x,y,r;
        cin >> x >> y >> r;
        ll dx = r,dy=1;
        paren[y].pb(x-dx,+1);
        paren[y].pb(x+dx,-1);

        forn(_,r){
            if(dy>r)break;
            while(dx*dx+dy*dy>r*r)dx--;
            if(y-dy>=0){paren[y-dy].pb(x-dx,+1);paren[y-dy].pb(x+dx,-1);}
            if(y+dy<h){paren[y+dy].pb(x-dx,+1);paren[y+dy].pb(x+dx,-1);}
            dy++;
        }
    }

    ll res=0;
    forn(y,h){
        if(!si(paren[y]))res+=w;
        else{
            vector<pii> &row = paren[y];
            sort(all(row));
            res+=max(0,row[0].first);
            int ind=0;
            ll circ=0;
            while(ind<si(row)){
                ll xact=row[ind].first;

                while(ind< si(row) && row[ind].first==xact){
                    circ+=row[ind++].second;
                }
                if(!circ){
                    ll end=w;
                    if(ind < si(row))end=row[ind].first;
                    res+=max(0ll,end-(xact+1));
                }
            }
        }
    }

    cout << res << endl;

	return 0;
}

