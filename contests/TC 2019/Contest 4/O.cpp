#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forsn(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(a) a.begin(),a.end()
#define si(a) ((int)(a).size())
#define pb emplace_back
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

const int sz =8;
const int INF = 1e9;

int adj[10][10][10][10];

vi di = {-2,-1,+1,+2,+2,+1,-1,-2},
   dj = {+1,+2,+2,+1,-1,-2,-2,-1};

int main(){
    fastio;

    fill(adj[0][0][0],adj[10][0][0],INF);

    forn(i,sz){
        forn(j,sz){
            adj[i][j][i][j]=0;
            forn(k,si(di)){
                int ni = i+di[k];
                int nj = j+dj[k];

                if(0 <= ni && ni < sz &&
                   0 <= nj && nj < sz){
                    adj[i][j][ni][nj]=1;
                }
            }
        }
    }

    forn(ki,sz){
        forn(kj,sz){
            forn(ii,sz){
                forn(ij,sz){
                    forn(ji,sz){
                        forn(jj,sz){
                            adj[ii][ij][ji][jj] =
                                min(adj[ii][ij][ji][jj],
                                        adj[ii][ij][ki][kj]+adj[ki][kj][ji][jj]);
                        }
                    }
                }
            }
        }
    }
    //cerr << "FLOYD done"<<endl;
    //forn(ji,sz){
    //    forn(jj,sz){
    //        cerr << adj[0][0][ji][jj] <<  " ";
    //    }
    //    cerr << endl;
    //}

    string p1,p2;
    while(cin >> p1 >> p2){
        int p1i = p1[1]-'1', p1j=p1[0]-'a';
        int p2i = p2[1]-'1', p2j=p2[0]-'a';
        //cerr << p1i << " " << p1j << endl << p2i << " " << p2j << endl;
        cout << "To get from " << p1 << " to " << p2 << " takes " <<adj[p1i][p1j][p2i][p2j] << " knight moves." << endl;
    }


    return 0;
}
