#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; // key, mapped, comp
using indexed_set = tree<int, null_type, less<int>, 
rb_tree_tag, tree_order_statistics_node_update>;
// use STL methods like: insert, erase, etc
// find_by_order(k): iterator to k-th element
// order_of_key(x): index of lower bound of x
// to use it as multiset use pair<key, timestamp>
