// Para max pasar less y -INF
template <class T, class Compare, T INF>
struct RMQ { 
    deque<T> d; queue<T> q;
    void push(T v) { 
        while (!d.empty() && Compare()(d.back(), v)) d.pop_back(); 
        d.pb(v), q.push(v);
    }
    void pop() { 
        if (!d.empty() && d.front()==q.front()) d.pop_front(); 
        q.pop(); 
    }
    T getMax() { return d.empty() ? INF : d.front(); }
    int size() { return si(q); }
};
RMQ<ll, less<ll>, -INF> rmq;
