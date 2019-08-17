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

const int MAXN = 55;

ll memo[MAXN][MAXN];

int main() {
	fastio;

    fill(memo[0],memo[0]+MAXN,1ll);
    fill(memo[1],memo[1]+MAXN,2ll);
    memo[1][1]=1;

    forsn(i,2,MAXN){
        memo[i][0]=memo[i-1][1]+(1ll<<(ll)(i-1));
        forsn(j,1,MAXN-1){
            memo[i][j]=memo[i-1][j+1]+memo[i-1][j-1];
        }
    }
	
    int q;
    cin >> q;
    while (q--){
        ll n, k;
        cin >> n >> k;
        if (memo[n][0]<k)cout << -1 << endl;
        else{
            string res = "";
            int dif =0;
            while (n --> 0){
                if (dif >=0){
                    if (memo[n][dif+1]>=k){
                        res+='(';
                        dif++;
                    }
                    else{
                        k-=memo[n][dif+1];
                        res+=')';
                        dif--;
                    }
                }
                else{
                    if ((1ll<<(ll)n) >= k){
                        res+= '(';
                    }
                    else{
                        res+= ')';
                        k-=(1ll<<(ll)n);
                    }
                }
            }
            cout << res << endl;
        }
    }
	
	return 0;
}

