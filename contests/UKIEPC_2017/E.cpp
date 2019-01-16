
#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
    #define RAYA cerr << "----------" << endl
#else
    #define DBG(a)
    #define RAYA
    #define endl '\n'
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;


struct b{
    int ind,cap,cost;
    b(){}
    b(int _ind,int _cap,int _cost):ind(_ind),cap(_cap),cost(_cost){}
    bool operator <(const b &o)const{
        return cap>o.cap;
    }
    bool operator ()(const b& n,const b& m) const{
        return n.cost>m.cost;
    }
};
priority_queue<b,vector<b>,b> pq;

int main() {
	fastio;

    int n,m;
    cin >> n >>m;

    vector<pii> dept(n);
    forn(i,n){
        cin >> dept[i].first;
        dept[i].second=i;
    }

    vector<b>building(m);
    forn(i,m){
        cin >> building[i].cap;
        building[i].ind=i+1;
    }
    forn(i,m){
        cin >> building[i].cost;
    }
    sort(all(dept),greater<pii>());
    sort(all(building));
    int ind=0;
    bool can=true;
    vi res(n);
    for(int i=0;i<n&&can;i++){
        while(ind<si(building)&&building[ind].cap>=dept[i].first){
            pq.emplace(building[ind]);
            ind++;
        }
        if(pq.empty())can=false;
        else{
            res[dept[i].second]=pq.top().ind;
            pq.pop();
        }
    }

    if(can){
        forn(i,si(res))cout << (i?" ":"") << res[i];
        cout << endl;
    }
    else cout <<"impossible"<<endl;


	return 0;
}
