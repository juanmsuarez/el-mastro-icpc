#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forsn(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(a) a.begin(),a.end()
#define si(a) ((int)(a).size())
#define pb emplace_back
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fst first
#define snd second
using vi = vector<int>;
using ll = long long;
using pii = pair<int,int>;

struct Quilt {
    bool error;
    vector<vector<char>> v;

    Quilt() : error(false) {}

    Quilt sew(Quilt other) {
        if (error || other.error || si(v) != si(other.v)) error = true; 
        else {
            forn(i, si(v)) 
                v[i].insert(v[i].end(), all(other.v[i]));
        }

        return *this;
    }

    char turn(char c) {
        if (c == '+') return '+';
        if (c == '/') return '\\';
        if (c == '\\') return '/';
        if (c == '-') return '|';
        if (c == '|') return '-';
        return ' ';
    }

    Quilt turn() {
        if (error) return *this;

        int n = si(v), m = si(v[0]);
        vector<vector<char>> w(m, vector<char>(n));

        forn(i, n)
            forn(j, m)
                w[j][n-1-i] = turn(v[i][j]);

        v = w;

        return *this;
    }
};

Quilt A, B;

void print(Quilt q) {
    for (vector<char> &w : q.v) {
        for (char c : w) cout << c;
        cout << endl;
    }
}

int opLength(string s) {
    if (s[0] == 'A' || s[0] == 'B') return 1;

    int pos = s.find('(');
    if (pos == string::npos) return 1;

    pos++;
    int p = 1;
    while (p != 0) {
        if (s[pos] == '(') p++;
        else if (s[pos] == ')') p--;
        pos++;
    }

    return pos;
}

Quilt op(string s) {
    if (s == "A") return A;
    else if (s == "B") return B;
    else {
        int open = s.find('(');
        string type = s.substr(0, open);

        string t = s.substr(open+1, si(s)-open-2);
        if (type == "turn") {
            Quilt quilt = op(t);
            quilt.turn();
            return quilt;
        }
        else { // sew
            int open = t.find('('), length = opLength(t);
            Quilt quilt1 = op(t.substr(0, length)), quilt2 = op(t.substr(length+1)); 
            quilt1.sew(quilt2);
            return quilt1;
        }
    }
}

void parse(string s) {
    int caso = 0;
    
    string t;
    for (char c : s) {
        if (c == ';') {
            cout << "Quilt " << caso+1 << ": " << endl;
            Quilt result = op(t);
            if (result.error) cout << "error" << endl;
            else print(result);

            t = "";
            caso++;
        }
        else t += c;
    }
}

int main(){
    fastio;

    A.v = {{'/', '/'}, {'/', '+'}};
    B.v = {{'-', '-'}, {'-', '-'}};

    string s, t;
    while (cin >> t) s += t;

    parse(s);

    return 0;
}
