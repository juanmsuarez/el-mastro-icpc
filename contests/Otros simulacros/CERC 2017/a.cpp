#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl
#else 
    #define D(a) 8 
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define all(a) (a).begin(),(a).end()
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int r,n;
int leftSide,rightSide;

struct Row {
    int ind, seats;
    Row(int i,int s):ind(i),seats(s){}

    inline int dist()const{
        return min(ind-1,min(abs(r/2+2-ind),r+3-ind));
    }

    inline bool afterExit()const{
        return ind == 2 || ind == r/2+3;
    }

    bool operator <(const Row &o)const{
        if(ind == o.ind)return false;
        if(afterExit() && !o.afterExit())return false;
        if(!afterExit() && o.afterExit())return true;
        if(seats!=o.seats)return seats < o.seats;
        if(dist()!=o.dist())return dist() > o.dist();
        return ind > o.ind;
    }

};

vector<string> seats;

vector<pii> options = { {4,6},{2,8},{0,10},{5,5},{1,9}};
int choose(int row){
    for(auto [i,j]:options){
        if(seats[row][i]=='-' && seats[row][j]=='-'){
            return rightSide < leftSide ? j : i;
        }
        if(seats[row][i]=='-')return i;
        if(seats[row][j]=='-')return j;
    }

}

int main() {
    fastio;
    
    cin >> r >> n;
    seats = vector<string>(r+4);
    priority_queue<Row> pq;
    leftSide=0,rightSide=0;
    forn(i,r+3){
        string row;
        cin >> row;
        seats[i+1]=row;
        if(i && i+1!=r/2+2 && i<r+2){
            int empty=0;
            forn(c,si(row)){
                if(row[c]=='-'){
                    empty++;
                }
                else if(row[c]=='#'){
                    if(c<5)leftSide++;
                    else if(c>5)rightSide++;
                }
            }
            if(empty)pq.emplace(i+1,empty);

            
        }
        else D(row);
    }

    forn(i,n){
        auto [ind,empty] = pq.top();pq.pop();
        empty--;
        int col = choose(ind);
        seats[ind][col]=(char)('a'+i);
        if(col<5)leftSide++;
        else if(col>5)rightSide++;
        if(empty)pq.emplace(ind,empty);
    }
    forsn(i,1,si(seats))cout << seats[i] << endl;
    
    return 0;
}

