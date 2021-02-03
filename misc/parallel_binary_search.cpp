using QueryInRange = tuple<int, int, int>;

void init(); // reset values to start
void add(int k); // work that is common to multiple queries
bool can(int q); // usual check

vi ans; // resize to q
void binary_search(int start, int end, vi query_ids) {
    vector<QueryInRange> queries; 
    for (int id : query_ids) queries.pb(start, end, id);

    while (!queries.empty()) {
        vector<QueryInRange> next_queries; 

        int progress = 0;
        init();

        for (auto &query : queries) {
            int lo, hi, id; tie(lo, hi, id) = query;
            if (lo + 1 == hi) continue;

            int mid = (lo + hi) / 2;
            while (progress < mid) add(progress++);

            if (can(id)) ans[id] = mid, next_queries.pb(lo, mid, id);
            else next_queries.pb(mid, hi, id);
        }

        sort(all(next_queries));

        queries = next_queries;
    }
}
