#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i = 0; i <(int)(n); i++)
#define forsn(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define dforsn(i,s,n) for (int i = (int)(n-1); i >= (int)(s); i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define si(v) ((int)v.size())
#define DBG(a) cerr << #a << " " << a << endl;
typedef vector<int> vi;

#define MAXN int(1e5+100)
#define operacion(x,y) (x+y)
const int neutro=0;
struct RMQ{
    int sz;
    int t[4*MAXN];
    int &operator[](int p){return t[sz+p];}
    void init(int n){
        sz=1<<(32-__builtin_clz(n));
        forn(i,2*sz)t[i]=neutro;
    }
    void updall(){
        dforsn(i,0,sz)t[i]=operacion(t[2*i],t[2*i+1]);}
    int get(int i,int j){return get(i,j,1,0,sz);}
    int get(int i,int j,int n,int a,int b){
        if(j<=a || i>=b)return neutro;
        if(i<=a && b<=j)return t[n];
        int c =(a+b)/2;
        return operacion(get(i,j,2*n,a,c),get(i,j,2*n+1,c,b));
    }
    void upd(int p,int val){
        for(p+=sz;p>0&&t[p]!=val;){
            t[p]=val;
            p/=2;
            val=operacion(t[p*2],t[p*2+1]);
        }
    }
}rmq;

struct rec{
    int i,f,v;
    rec(int _i,int _f,int _v):i(_i),f(_f),v(_v){}
};

set<int>finals;
int main(){
    //freopen("in.txt", "r", stdin);

    vector<rec>cur;
    vi ids(MAXN,-1);
    int q;
    cin>>q;
    rmq.init(MAXN);
    forn(_,q){
        int tp;
        cin >> tp;
        if(tp==1){
            int i,f,v;
            cin >> i >> f >> v;
            cur.emplace_back(i,f,v);
            rmq.upd(i,v);
            finals.insert(f);
            ids[f]=si(cur)-1;
        }
        if(tp==2){
            int k;
            cin >> k;
            rmq.upd(cur[k-1].i,0);
            finals.erase(cur[k-1].f);
            ids[cur[k-1].f]=-1;
        }
        if(tp==3){
            int a,b;
            cin >> a>> b;
            int res=rmq.get(a,b);
            //DBG(res);
            auto ptr = finals.upper_bound(a);
            if(ptr!=finals.end()){
                int intf = *ptr;
                int intk = ids[intf];
                if(cur[intk].i<a)res+=cur[intk].v;
            }
            cout << res << endl;
        }
    }
}

/*
struct node{
    int l,r,val=0;
    node *left,*right;
    node(int _l,int _r):l(_l),r(_r){
        left=new node(l,(l+r)/2);
        right=new node((l+r)/2,r);
    }
}*/
