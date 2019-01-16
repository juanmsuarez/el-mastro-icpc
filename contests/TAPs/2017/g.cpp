#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i = 0; i <(int)(n); i++)
#define forsn(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define pb push_back
#define all(v) v.begin(), v.end()
typedef vector<int> vi;
typedef long long int tint;

tint memo[110][1010];
tint suma[110][1010];
tint comb[110][110];
const tint MOD=1e9+7;

int main(){
    forn(i, 110) {
        comb[i][0] = comb[i][i] = 1;
        forsn(k,1,i) comb[i][k] = (comb[i-1][k]+comb[i-1][k-1])%MOD;
    }

    tint N, M, P1, P2;
    cin>>N>>M>>P1>>P2;
    tint P=max(P1,P2)+1;
    memo[0][0]=1;
    for(int i=1;i<=P;i++) memo[0][i]=0;
    for(int i=1;i<=N;i++) memo[i][0]=0;
    suma[0][0]=0;
    for(int i=1;i<=P+1;i++) suma[0][i]=1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=P;j++){
            int aux=j-M;
            if(aux<0) aux=0;
            memo[i][j]=suma[i-1][j]-suma[i-1][aux];
            memo[i][j]=(memo[i][j]+MOD)%MOD;
        }
        for(int j=1;j<=P+1;j++){
            suma[i][j]=memo[i][j-1]+suma[i][j-1];
            suma[i][j]%=MOD;
        }
    }
    tint res=0, posA=0, posB=0;
    for(int a=1;a<=N;a++){
        posA=memo[a][P1];
        for(int b=1;a+b<=N;b++){
            posB=memo[b][P2];
            res+=posA*posB%MOD*comb[N][a]%MOD*comb[N-a][b]%MOD;
            res%=MOD;
        }

    }
    cout << res << endl;
    return 0;

}
