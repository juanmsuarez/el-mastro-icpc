#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define all(c) c.begin(), c.end()
const int N = 111;

int c, v, fav, pref[N][N], rpref[N][N], best[N];
string tmp[N][N];
vector<string> coord;
bool used[N];

int s2i(const string &s) { return lower_bound(all(coord), s) - coord.begin(); }

int votes(int x) {
    int ans = 0;
    forn(voter,v) {
        int ind = 0;
        while (ind < c && used[pref[voter][ind]]) ++ind;
        if (ind < c && pref[voter][ind] == x) ++ans;
    }
    return ans;
}

int possible() {
    vector<int> votes(c), good, best(v);
    forn(voter,v) {
        best[voter] = rpref[voter][fav];
        forn(cand,c) votes[cand] += rpref[voter][cand] < best[voter];
    }
    forn(cand,c) if (cand != fav && !used[cand] && votes[cand]*2 < v)
        good.push_back(cand);

    int took = 1;
    while (!good.empty()) {
        auto u = good.back();
        ++took;
        good.pop_back();
        forn(voter,v) {
            auto nbest = min(best[voter], rpref[voter][u]);
            while (best[voter] > nbest) {
                --best[voter];
                auto cand = pref[voter][best[voter]];
                --votes[cand];
                if (!used[cand] && 2*votes[cand] < v && 2*(votes[cand]+1) > v) 
                    good.push_back(cand);
            }
        }
    }
    return took;
}


int main() {
    // Input
    cin >> c >> v;
    forn(i,v) forn(j,c) {
        cin >> tmp[i][j];
        coord.push_back(tmp[i][j]);
    }

    // coord comprension
    sort(all(coord));
    coord.erase(unique(all(coord)), coord.end());
    forn(i,v) forn(j,c) {
        pref[i][j] = s2i(tmp[i][j]);
        rpref[i][pref[i][j]] = j;
    }

    {
        string name; cin >> name;
        fav = s2i(name);
    }

    if (possible()+1 < c) return cout << "*", 0;

    vector<int> ans(c);
    forn(i,c) {
        forn(x,c) if (!used[x]) {
            if (x == fav && 2*votes(x) < v) continue;
            if (!used[fav] && x != fav && 2*votes(x) > v) continue;

            used[x] = 1;
            if (possible()+i+1 >= c) {
                ans[i] = x;
                break;
            }
            used[x] = 0;
        }
    }
    for (int ind : ans) cout << coord[ind] << ' ';
    return 0;
}
