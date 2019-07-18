
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl;
#else
    #define D(a)
    #define cerr false && cerr
#endif
#define forsn(i,s,n) for(int i = (int)s; i < (int) n;i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i = (int)(n-1); i >= (int) s;i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb emplace_back
#define si(a) ((int)(a).size())
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using pii = pair<int,int>;
using ll = long long int;
using vi = vector<int>;

struct pto{
    int x,y;
    bool operator ==(const pto &o)const{
        return x==o.x&&y==o.y;
    }
    bool operator <(const pto &o)const{
        return make_pair(x,y)<make_pair(o.x,o.y);
    }
};

struct state{
    pto p1,p2,p3;
    int turn;
    bool operator ==(const state &o)const {
        return p1==o.p1 && p2==o.p2&&p3==o.p3&&turn==o.turn;
    }
    bool operator <(const state &o)const {
        return make_tuple(p1,p2,p3,turn) < make_tuple(o.p1,o.p2,o.p3,o.turn);
    }

}target;

bool isTarget(state &o){
    return target.p1==o.p1 && target.p2==o.p2&&target.p3==o.p3;
}

set<state> visited;
queue<pair<state,int>>q;

bool inBoard(pto p){
    return 0 <= p.x && p.x <= 7 && 0 <= p.y && p.y <= 7;
}

vi cabx ={-2,-1,+1,+2,+2,+1,-1,-2},
    caby ={+1,+2,+2,+1,-1,-2,-2,-1};
void caballo(state &act,int turns){
    forn(k,si(cabx)){
        pto pos = (pto){act.p1.x+cabx[k],act.p2.y+caby[k]};
        if(inBoard(pos) &&!(pos==act.p2)&&!(pos==act.p3)){
            state nxt = (state){pos,act.p2,act.p3,(act.turn+1)%3};
            if(!visited.count(nxt)){
                q.emplace(nxt,turns+1);
                visited.insert(nxt);
            }
        }
    }
}

vi torrx ={+0,+1,+0,-1},
    torry ={+1,+0,-1,+0};
void torre(state &act,int turns){
    forn(k,si(torrx)){
        int ind=1;
        bool can=true;
        while(can){
            pto pos = (pto){act.p2.x+ind*torrx[k],act.p2.y+ind*torry[k]};
            if(inBoard(pos) &&!(pos==act.p1)&&!(pos==act.p3)){
                state nxt = (state){act.p1,pos,act.p3,(act.turn+1)%3};
                if(!visited.count(nxt)){
                    q.emplace(nxt,turns+1);
                    visited.insert(nxt);
                }
            }
            else can=false;
            ind++;
        }
    }
}

vi alfx ={-1,+1,+1,-1},
    alfy ={+1,+1,-1,-1};
void alfil(state &act,int turns){
    forn(k,si(alfx)){
        int ind=1;
        bool can=true;
        while(can){
            pto pos = (pto){act.p3.x+ind*alfx[k],act.p3.y+ind*alfy[k]};
            if(inBoard(pos) &&!(pos==act.p1)&&!(pos==act.p2)){
                state nxt = (state){act.p1,act.p2,pos,(act.turn+1)%3};
                if(!visited.count(nxt)){
                    q.emplace(nxt,turns+1);
                    visited.insert(nxt);
                }
            }
            else can=false;
            ind++;
        }
    }
}

int main(){
        fastio;

        int t;
        cin >> t;


        while(t--){
            state start;
            cin >> start.p1.x >> start.p1.y >>start.p2.x >> start.p2.y >>start.p3.x >> start.p3.y;
            start.turn=0;
            target={start.p3,start.p1,start.p2,0};
            visited.clear();
            q= queue<pair<state,int>>();

            q.emplace(start,0);            

            int res=-1;
            while(!q.empty()){
                state act = q.front().first;
                int turns=q.front().second;
                q.pop();
                if(isTarget(act)){
                    res = turns;
                    break;
                }
                if(act.turn==0)caballo(act,turns);
                else if(act.turn==1)torre(act,turns);
                else if(act.turn==2)alfil(act,turns);
            }
            cout << res << endl;
            //cerr << si(visited) << endl;
        }

        

        return 0; 
}
