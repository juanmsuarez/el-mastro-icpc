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

struct query{
    int num;
    pii ans;
    query(){}
    query(int n,int x,int y):num(n){
        ans=mp(x,y);
    }
};

bool difdig(int n){
    vector<bool> digs(10,false);
    forn(i,4){
        int d = n%10;
        if(digs[d])return false;
        digs[d]=true;
        n/=10;
    }
    return true;
}

pii check(int a,int b){
    int cow=0,bull=0;
    vi seqa,seqb;
    forn(k,4){
        if(a%10==b%10)cow++;
        else{
            seqa.pb(a%10);
            seqb.pb(b%10);
        }
        a/=10;
        b/=10;
    }
    forn(i,si(seqa)){
        forn(j,si(seqb)){
            if(seqa[i]==seqb[j]){
                bull++;
                break;
            }
        }
    }
    return mp(cow,bull);
}

int main() {
    fastio;

    int n;
    cin >> n;
    vector<query>qs(n);
    for(query &q:qs){
        cin>> q.num >> q.ans.first >> q.ans.second;
    }
    vi res;
    forn(i,1e4){
        bool valid=difdig(i);
        for(int j=0;j<n&&valid;j++){
            valid=(check(i,qs[j].num)==qs[j].ans);
        }   
        if(valid){
            res.pb(i);
        }
    }
    if(si(res)>1)cout << "Need more data" << endl;
    else if(!si(res))cout << "Incorrect data"<<endl;
    else cout <<setfill('0') << setw(4) <<  *res.begin()<<endl;

    return 0;
}
