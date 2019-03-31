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

struct run{
    string n;
    double a,b;
    run(string n,double a,double b):n(n),a(a),b(b){}
    run(){
        n="";
        a=0;
        b=0;
    }
    
    bool operator <(const run &o)const{
        return b>o.b;
    }
};

int main() {
    fastio;
    
    int n;
    cin >>n;


    vector<run>seq;
    forn(i,n){
        string n;
        double a,b;
        cin >> n>>a>>b;
        seq.eb(n,a,b);
    }
    double mintime=seq[0].a+seq[1].b+seq[2].b+seq[3].b;
    vector<run>res = {seq[0],seq[1],seq[2],seq[3]};
    forn(i,n){
        priority_queue<run> pq;
        run first = seq[i];
        forn(j,n){
            if(j!=i)pq.emplace(seq[j]);
        }
        vector<run>act(4);
        act[0]=first;
        double tact=first.a;
        forn(i,3){
            tact+=pq.top().b;
            act[i+1]=pq.top();
            pq.pop();
        }
        if(tact<mintime){
            mintime=tact;
            res=act;
        }
    }
    cout <<mintime<<"\n";
    forn(i,si(res)){
        cout<<res[i].n<<"\n";
    }



    return 0;
}
