#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i = (int)s; i < (int)n;i++)
#define forn(i,n) forsn(i,0,n)
#define pb emplace_back
#define si(a) int(a.size())
using vi = vector<int>;

int main(){
    int n,m; cin >> n >> m;
    vector<vector<char>> a(n);
    forn(i,n) a[i].resize(m);
    vi col(m),row(n);
    forn(i,n) forn(j,m) cin >> a[i][j];
    int t = 0;
    forn(i,n) forn(j,m) if(a[i][j] == '*') row[i]++, col[j]++, t++;
    cerr << t << endl;
    forn(i,n) forn(j,m) if(row[i] + col[j] - (a[i][j]=='*') == t){
        cerr << row[i] << endl;
        cerr << col[j] << endl;
        cout << "YES\n" << i+1 << " " << j+1 << endl;
        return 0;
    }
    return cout << "NO\n", 0;
}
