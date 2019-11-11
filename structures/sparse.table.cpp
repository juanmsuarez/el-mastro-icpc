// The operation has to be associative and idempotent
#define lg(n) 31 - __builtin_clz(n)
typedef int T; 
struct RMQ {
    const static int K = 10; // 2^K > N
    T t[K][1 << K];
    T& operator[](int p){ return t[0][p]; }
    T get(int i, int j){ // O(1), [i, j)
        int p = lg(j-i);
        return min(t[p][i], t[p][j - (1 << p)]);
    }
    void build(int n){ // O(n log n)
        forn(p, lg(n)) forn(x, n - (1 << p))
            t[p + 1][x] = min(t[p][x], t[p][x + (1 << p)]);
    }
} rmq;
