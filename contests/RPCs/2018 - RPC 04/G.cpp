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
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

int cantS(int r){
    if(r>=21)return 2;
    if(r>=16)return 3;
    if(r>=11)return 4;
    return 5;
}

int main() {
    fastio;

    string s;
    cin >> s;

    int streak=0;
    int stars=0;
    int rank=25;
    for(auto m:s){
        if(!rank)break;
        if(m=='W'){
            streak++;
            stars++;
            if(rank>=6&&streak>=3)stars++;
            if(stars>cantS(rank)){
                stars-=cantS(rank);
                rank--;
            }
        }
        else{
            streak=0;
            if(rank<20 || (rank==20 && stars>0)){
                stars--;
                if(stars<0){
                    rank++;
                    stars=cantS(rank)-1;
                }
            }
        }
    }
    if(rank)cout << rank << endl;
    else cout << "Legend" << endl;

    return 0;
}
