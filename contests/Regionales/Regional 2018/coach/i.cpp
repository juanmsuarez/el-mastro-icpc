#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

#define NOTHING 0
#define LEGS 1
#define BODY 2

int n;
vector<int> adj[N];

int man[N], type[N];
int dfs(int u, int p) {

    man[u] = 0;
    vector<int> cnt(3);
    for (int v : adj[u]) if (v != p) {
        dfs(v,u);
        man[u] += man[v];
        cnt[type[v]]++;
    }
    man[u] += cnt[BODY];
    if (cnt[LEGS] >= 1 && (cnt[LEGS] + cnt[NOTHING] >= 3))
        type[u] = BODY;
    else if (cnt[LEGS] + cnt[NOTHING] >= 2)
        type[u] = LEGS;
    else 
        type[u] = NOTHING;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p; cin >> p; --p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    dfs(0,0);
    cout << man[0] << endl;
    return 0;
}


