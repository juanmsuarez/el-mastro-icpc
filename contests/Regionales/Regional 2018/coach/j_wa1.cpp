#include <bits/stdc++.h>
using namespace std;

const int N = 111;

int c,v,imine;
string pref[N][N];
int ipref[N][N], rpref[N][N];
int rival[N], used[N];

#define all(c) (c).begin(), (c).end()

int best[N];
void relax(int cand) {
    for (int voter = 0; voter < v; voter++) 
        best[voter] = min(best[voter], rpref[voter][cand]);
}

int wouldWin(int cand) {
    int ans = 0;
    for (int voter = 0; voter < v; voter++) 
        if (best[voter] > rpref[voter][cand]) ++ans;
    return ans;
}

bool go(set<int> &first) {
    while (!first.empty()) {
        bool ok = 0;
        for (auto cand : first) {
            if (wouldWin(cand)*2 <= v) {
                relax(cand);
                first.erase(cand);
                ok = 1;
                break;
            }
            if (!ok) return 0;
        }
    }
    return 1;
}

bool winsA() {
    fill_n(best, N, N);
    for (int cand = 0; cand < c; cand++) if (!used[cand]) {
        relax(cand);
    }
    int ans = 0;
    for (int i = 0; i < v; i++) ans += (best[i] >= rpref[i][imine]);
    return 2*ans > v;
}


bool poss(int last) {
    if (used[imine]) return winsA();

    set<int> first;
    for (int i = 0; i < c; i++) if (rival[i] && !used[i]) first.insert(i);

    set<int> second;
    for (int i = 0; i < c; i++) if (used[i]) second.insert(i);

    fill_n(best, N, N);
    for (int i = 0; i < c; i++) {
        if (!rival[i] && !used[i]) 
            relax(i);
    }
    bool ans = go(first);
    if (wouldWin(last)*2 > v) return 0;
    return ans;
}

int main() {
    cin >> c >> v;
    vector<string> cand;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < c; j++) {
            cin >> pref[i][j];
            cand.push_back(pref[i][j]);
        }
    }
    sort(all(cand));
    cand.erase(unique(all(cand)), cand.end());
    vector<vector<int>> ipref(v, vector<int>(c));
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < c; j++) {
            ipref[i][j] = lower_bound(all(cand), pref[i][j]) - cand.begin();
            rpref[i][ipref[i][j]] = j;
        }
    }

    string mine; cin >> mine;
    imine = lower_bound(all(cand), mine) - cand.begin();
 
    for (int i = 0; i < c; i++) {
        int win = 0;
        for (int j = 0; j < v; j++) win += rpref[j][i] < rpref[j][imine];
        if (2*win > v) rival[i] = 1;
    }

    bool thereis = 1;
    vector<int> ans(c);
    for (int i = 0; i < c; i++) {
        //cerr << i << ' ' << winsA() << endl;
        //for (int j = 0; j < c; j++) cerr << used[j]; cerr << endl;

        bool ok = 0;
        for (int x = 0; x < c; x++) if (!used[x]) {
            if (x == imine && !winsA()) continue;
            //if (x != imine && !used[imine] && wouldWin(x)*2 > v) continue;
            used[x] = 1;
            if (poss(x)) {
                ans[i] = x;
                ok = 1;
                //cerr << "??" << x << endl;
                break;
            }
            else used[x] = 0;
        }
        thereis &= ok;
    }
    if (thereis) for (auto ind : ans) cout << cand[ind] << ' ';
    else cout << "*" << endl;
    return 0;
}
