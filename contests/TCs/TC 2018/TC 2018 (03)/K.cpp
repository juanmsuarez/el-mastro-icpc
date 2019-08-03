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
typedef tuple<int,int,int,int> fila;

const int MAXN = 15, MAXF = 8;
bool print[MAXN][MAXN];

int sumas[MAXF];
int filas[MAXN][2] = {{0, 1}, {2, 3}, {0, 2}, {1, 2}, {2, 4}, {0, 3}, {1, 4},
    {0, 5}, {3, 5}, {4, 5}, {1, 5}, {3, 4}};
int check[MAXF] = {7, 10, 4, 11, 11, 10};

int ind = 0;
vi v, val;
bool used[MAXN];

bool bt() {
    if (ind == 12) 
        return true;         
    
    forn(k, 12) {
        if ((val[ind] != -1 && k != val[ind]) || used[k]) continue;

        bool can = true;
        forn(i, 2) {
            int f = filas[ind][i];
            sumas[f] += k+1;
            if (check[f] == ind) {
                if (sumas[f] != 26) can = false;
            }
            else
                if (sumas[f] >= 26) can = false;
        }
        used[k] = true;
        v.pb(k);
        ind++;

        if (can && bt()) return true;

        ind--;
        forn(i, 2) {
            int f = filas[ind][i];
            sumas[f] -= k+1;
        }
        used[k] = false;
        v.pop_back();
    }        

    return false;
}

int main() {
    fastio;

    forn(i, 5) {
        forn(j, 9) {
            char a;
            cin >> a;
            if (a != '.') {
                if (a == 'x')
                    val.pb(-1);
                else
                    val.pb(a-'A');
                print[i][j] = true;
            }
        }
    }    

    bt();

    int k = 0;
    forn(i, 5) {
        forn(j, 9) {
            if (print[i][j]) cout << char('A'+v[k++]);
            else cout << '.';
        }
        cout << endl;
    }

    return 0;
}
