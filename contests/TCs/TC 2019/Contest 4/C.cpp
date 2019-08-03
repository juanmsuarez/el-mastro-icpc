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

const int INF = 1000;

int main() {
	fastio;

    int t;
    cin >> t;
    while(t--){
	
        int n,m;
        cin >> n >> m;
        vector<vi> prefsum(n+1,vi(m+1));
        vector<vi> a(n,vi(m));

        forn(i,n){
            forn(j,m){
                cin >> a[i][j];
                if(!a[i][j])a[i][j]--;
                prefsum[i+1][j] += a[i][j] +prefsum[i][j];
            }
        }

        int res=0;
        int resval=-INF;
        forn(i,n){
            forsn(j,i,n){
                int maxC=prefsum[j+1][0]-prefsum[i][0];
                int maxval=maxC;
                int cant=1;
                int cantC=1;
                if(maxC<0){
                    maxC=0;
                    cantC=0;
                }
                forsn(k,1,m){
                    //D(k);
                    //D(maxC);
                    //D(cantC);
                    int d = a[i][k];
                    if(i!=j)d+=a[j][k];
                    int Cact=prefsum[j+1][k]-prefsum[i][k];
                    int act = maxC+ Cact;
                    if(act>maxval){
                        maxval=act; 
                        cant = 0;
                    }
                    if(act==maxval){
                        cant+=cantC;
                        if(maxC==0)cant++;
                    }
                    
                    maxC+=d;
                    if(maxC<=0){
                        if(maxC<0)cantC=0;
                        maxC=0;
                    }
                    if(Cact > maxC){
                        maxC=Cact;
                        cantC=1;
                    }
                    else if(Cact==maxC)cantC++; 
                }
                if(maxval >resval){
                    resval=maxval;
                    res=cant;
                }
                else if(maxval ==resval)res+=cant;
            } 
        }

        cout << resval << " " <<res << endl;
    }


	return 0;
} 
