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
    #define DBG(a) ////cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

string nxt(string &s, int p) {
    string t; 
    ////cerr << "n " << s << ' ' << p << endl;

    while (p < si(s) && s[p] != ' ')
        t += s[p++];

    return t;
}

const int MAXW = 2e6+10;
int g(map<string, int> &m, string rev[], string &s) {
    if (m.count(s)) return m[s];
    else { 
        int k = si(m);
        rev[k] = s;
        return m[s] = k;
    }
}

set<int> wordUsers[MAXW];
int wordCount[MAXW];
string revWord[MAXW], revUser[MAXW];

int main() {
    fastio;

    string _;

    int m;
    cin >> m;
    getline(cin, _);

    map<string, int> wordId, userId;

    while (m--) {
        string s;
        getline(cin, s);
        ////cerr << s << endl;

        string user = nxt(s, 0);
        int uId = g(userId, revUser, user);        

        ////cerr << "user " << user << endl;
        int p = si(user) + 1;
        string word;
        while (si(word = nxt(s, p)) > 0) {
            p += si(word) + 1;
            int wId = g(wordId, revWord, word);

            wordUsers[wId].insert(uId);
            wordCount[wId]++;
        }
    }

    //cerr << si(userId) << endl;
    vector<pair<int, string>> ans;
    forn(w, si(wordId)) {
        //cerr << w << ' ' << si(wordUsers[w]) << endl;
        if (si(wordUsers[w]) == si(userId))
            ans.pb(-wordCount[w], revWord[w]); 
    }
    sort(all(ans));

    if (si(ans) == 0) cout << "ALL CLEAR" << endl;
    else 
        for (pair<int,string> p : ans)
            cout << p.second << endl;

    return 0;
}
