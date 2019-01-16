#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define all(c) (c).begin(), (c).end()

const int N = 102;
int v,c,fav,pref[N][N], ipref[N][N];

struct election {
    int head[N], votes[N], present[N], wins;

    void updateVotes() {
        forn(j,c) votes[j] = 0;
        wins = fav;
        forn(i,v) {
            int c = pref[i][head[i]];
            votes[c]++;
            if (2*votes[c] > v) wins = c;
        }
    }

    void forwardHeads() {
        forn(i,v) while (head[i] < c && !present[pref[i][head[i]]]) head[i]++;
    }

    void init(const vector<bool> &present) {
        forn(i,v) head[i] = 0;
        forn(j,c) this->present[j] = present[j];
        forwardHeads();
        updateVotes();
    }

    void put(int c) {
        assert(!present[c]);
        present[c] = 1;
        forn(i,v) head[i] = min(head[i], ipref[i][c]);
        updateVotes();
    }

    void take(int c) {
        assert(present[c]);
        present[c] = 0;
        forwardHeads();
        updateVotes();
    }

    bool isPresent(int c) { return present[c]; }
};

string tmp[N][N];
vector<string> coord;
election elec, poss_elec;

bool poss() { 
    vector<bool> pres(c,0);
    pres[fav] = 1;
    poss_elec.init(pres);
    vector<bool> need(c,0);
    int left = 0;
    forn(j,c) if (j != fav && elec.isPresent(j)) need[j] = 1, ++left;
    while (left) {
        bool change = 0;
        forn(j,c) if (need[j]) {
            poss_elec.put(j);
            if (poss_elec.wins != fav) poss_elec.take(j);
            else {
                --left;
                need[j] = 0;
                change = 1;
            }
        }
        if (!change) break;
    }
    return left == 0;
}

int compr(const string &s) { return lower_bound(all(coord), s) - coord.begin(); }

int main() {
    while (cin >> c >> v) {
        coord.clear();
        forn(i,v) forn(j,c) {
            cin >> tmp[i][j];
            coord.push_back(tmp[i][j]);
        }
        sort(all(coord));
        coord.erase(unique(all(coord)), coord.end());
        forn(i,v) forn(j,c) pref[i][j] = compr(tmp[i][j]);
        forn(i,v) forn(j,c) ipref[i][pref[i][j]] = j;

        string fav_name; cin >> fav_name;
        fav = compr(fav_name);

        elec.init(vector<bool>(c,true));
        if (!poss()) return cout << "*\n", 0;

        vector<int> ans(c);
        for (int i = 0; i < c; i++) {
            for (int x = 0; x < c; x++) if (elec.isPresent(x)) {
                if (x == fav && elec.votes[x]*2 < v) continue;
                elec.take(x);
                if (poss()) {
                    ans[i] = x;
                    break;
                }
                else elec.put(x);
            }
        }
        forn(i,c) cout << coord[ans[i]] << (i+1 == c ? '\n' : ' ');
    }
    return 0;
}
