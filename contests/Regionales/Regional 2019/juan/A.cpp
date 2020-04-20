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

const int INF = 1e9;
const int T = 100, A = 10, N = T * (1<<A);

template<int MAXN>
struct Dinic {
    struct edge {
        int u,v; ll c,f;
        ll r() { return c-f; }
    };

    static const ll INF = 1e18;

    int N,S,T;
    vector<edge> e;
    //edge red[MAXN][MAXN];
    vi adjG[MAXN];

    void reset() {
        forn(u,N) for (auto ind : adjG[u]) {
            auto &ei = e[ind];
            ei.f = 0;
        }
    }

    void initGraph(int n, int s, int t) {
        N = n; S = s; T = t;
        e.clear();
        forn(u,N) adjG[u].clear();
    }

    void addEdge(int u, int v, ll c) {
        adjG[u].pb(si(e)); e.pb((edge){u,v,c,0});
        adjG[v].pb(si(e)); e.pb((edge){v,u,0,0});
    }

    int dist[MAXN];
    bool dinic_bfs() {
        forn(u,N) dist[u] = -1;
        queue<int> q; q.push(S); dist[S] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto ind : adjG[u]) {
                auto &ei = e[ind];
                int v = ei.v;
                if (dist[v] != -1 || ei.r() == 0) continue;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        return dist[T] != -1;
    }

    ll dinic_dfs(int u, ll cap) {
        if (u == T) return cap;

        ll res = 0;
        for (auto ind : adjG[u]) {
            auto &ei = e[ind], &ej = e[ind^1];
            int v = ei.v;
            if (ei.r() && dist[v] == dist[u] + 1) {
                ll send = dinic_dfs(v,min(cap, ei.r()));
                ei.f += send; ej.f -= send;
                res += send; cap -= send;
                if (cap == 0) break;
            }
        }
        if (res == 0) dist[u] = -1;
        return res;
    }

    ll flow() {
        ll res = 0;
        while (dinic_bfs()) res += dinic_dfs(S,INF);
        return res;
    }
};

Dinic<2*N + 2> dinic;
vi adj[N];

map<string, int> alg_ids;
int name_to_id(string name) {
    if (!alg_ids.count(name)) alg_ids[name] = si(alg_ids);
    return alg_ids[name];
}

int main() {
	fastio;
	
    // read
    int ts; cin >> ts; 
    vector<vi> teachers(ts);
    for (vi &algorithms : teachers) {
        int k; cin >> k; algorithms.resize(k);
        for (int &id : algorithms) {
            string name; cin >> name;
            id = name_to_id(name);
        }
    }

    // build students
    vector<vi> students;
    for (vi &algorithms : teachers) {
        int m = si(algorithms);
        for (int mask = 1; mask < (1<<m); mask++) {
            vi student;
            forn(k, m) if (mask & (1<<k)) student.pb(algorithms[k]);
            students.pb(student);
        }
    }

    for (vi &algorithms : students) sort(all(algorithms));
    sort(all(students));
    students.erase(unique(all(students)), students.end());

    // build poset (bipartite)
    int n = si(students), s = 2*n, t = 2*n + 1;
    dinic.initGraph(2*n + 2, s, t);

    forn(i, n) {
        dinic.addEdge(s, i, 1);
        dinic.addEdge(n + i, t, 1);
    }

    forn(i, n) {
        int m = si(students[i]);
        if (m == 1) continue;

        forn(k, m) {
            vi subset = students[i];
            subset.erase(subset.begin() + k);
            int j = lower_bound(all(students), subset) - students.begin();

            dinic.addEdge(i, n + j, INF);
        }
    } 

    // ans
    cout << n - dinic.flow() << endl;
	
	return 0;
}
