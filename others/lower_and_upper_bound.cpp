#include <bits/stdc++.h> 
using namespace std;

int main() {
	int a[] = {1, 2, 4, 7, 10};
	int v = 7;
	int *l = lower_bound(a,a+5,v);
	if(l == a+5) cout << "No luck" << endl;
	else cout << "First item not less than " << v << " is " << *l << endl;

	int *g = upper_bound(a,a+5,v);
	if(g == a+5) cout << "No luck" << endl;
	else cout << "First item greater than " << v << " is " << *g << endl;
	return 0;
}

/*
	Lower_bound is the first element that is not less than i, and upper_bound is the first element that is greater than i.
 	It's worth noting that lower_bound can be used as a binary search function, as if you're looking for a specific item and
 	it does exist, you'll get an iterator to it.
 	The last element that is less than or equivalent to x, is the element before the first element that is greater than x.
    Thus you can call upper_bound, and decrement the returned iterator once. (Before decrementing, you must of course check
    that it is not the begin iterator; if it is, then there are no elements that are less than or equivalent to x.)
*/