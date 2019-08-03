#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN=3e5+10,MAXP=1e7+10;
double cam[MAXN],rep[MAXN];
vi *pos[MAXP];
int rsort[MAXN];
pii interv[MAXN];

bool comp(int i,int j){
    return rep[i]<rep[j];
}

int main() {
    fastio;

	int m,n,d; cin >> m >> n >> d;
    const double eps = 1e-7;
	forn(i,m) cin >> cam[i];
	forn(i,n) cin >> rep[i];
	double res = 0, x = d*d - 1+eps;
    forn(i,n){
        vi *&vec=pos[(int)round(rep[i]*10)];
        if(!vec)vec=new vi();
        vec->pb(i);
    }

    int ind=0;
    forn(i,MAXP){
        if(pos[i]!=0)for(auto v:*pos[i])rsort[ind++]=v;
    }
    //forn(i,n)cerr << rep[rsort[i]] << " ";
    //cerr << endl;

    int l =0,r=0;
    forn(i,n){
        ind = rsort[i];
        while(l<m&&(rep[ind]-cam[l])*(rep[ind]-cam[l])>x)l++;
        r=l;
        while(r+1<m&&(rep[ind]-cam[r+1])*(rep[ind]-cam[r+1])<=x)r++;
        interv[ind]=mp(l,r);
    }
    //forn(i,n){
    //    D(i);
    //    D(interv[i].first);
    //    D(interv[i].second);
    //}
    ind=0;
    forn(i,n){
        l = interv[i].first,r=interv[i].second;
        if(ind<l){
            res+=cam[l]-cam[ind];
            ind=l;
        }
        else if(r<ind){
            res+=cam[ind]-cam[r];
            ind=r;
        }
    }
    cout << fixed << setprecision(2) << res << endl;
    return 0;
}
