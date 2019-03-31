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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef pair<double,double> pdd;

const double EPS =1e-6;
const int MAXN=30;
pair<double,double> memo[65][64][2][MAXN];

int dx[] = {+2,+2,+1,+1,-1,-1,-2,-2};
int dy[] = {+1,-1,+2,-2,+2,-2,+1,-1};

bool valid(pii p){
    return 0 <= p.fst && p.fst < 8 && 0<= p.snd && p.snd < 8;
}

pair<double,double> dp(pii a,pii b, bool turn=true,int n=0){
    if(n>=MAXN)return (pdd){0,0};
    pair<double,double> &res = memo[a.fst*8+a.snd][b.fst*8+b.snd][turn][n];
    if(res!=(pdd){-1,-1})return res;
    res=(pdd){0,0};

    if(a==b&&!turn)return res = (pdd){1,0};
    if(a==b&&turn)return res = (pdd){0,1};

    double cant=0;
    pii k = (turn?a:b);
    if(turn){
        forn(i,8){
            pii newk = mp(k.fst+dx[i],k.snd+dy[i]);
            if(valid(newk)){
                cant++;
                pdd im=dp(newk,b,!turn,n+1);
                res.fst+=im.fst;
                res.snd+=im.snd;
            }
        }
    }
    else{
        forn(i,8){
            pii newk = mp(k.fst+dx[i],k.snd+dy[i]);
            if(valid(newk)){
                cant++;
                pdd im=dp(a,newk,!turn,n+1);
                res.fst+=im.fst;
                res.snd+=im.snd;
            }
        }
    }
    res.fst/=cant;
    res.snd/=cant;
    
    return res;
}

int main() {
	fastio;
	
	pii a, b;

    cin >> a.fst >> a.snd >> b.fst >> b.snd;
    a.fst--;a.snd--;b.fst--;b.snd--;

    fill(memo[0][0][0],memo[64][0][0],(pdd){-1,-1});

    pair<double,double> res = dp(a,b);

    if(res.fst-res.snd> EPS)cout << "white"<<endl;
    else if(res.snd-res.fst>EPS)cout << "black" << endl;
    else cout << "draw" << endl;

	
	return 0;
}
