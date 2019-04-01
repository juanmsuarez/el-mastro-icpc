#include <bits/stdc++.h> // Library that includes the most used libraries
using namespace std;  // It avoids the use of std::func(), instead we can simply use func()

ios_base::sync_with_stdio(0); cin.tie(0); // Speeds up considerably the read speed, very convenient when the input is large

#pragma GCC optimize ("O3") // Asks the compiler to apply more optimizations, that way speeding up the program very much!

Math:
max(a,b);  // Returns the largest of a and b
min(a,b);  // Returns the smallest of a and b
abs(a,b);  // Returns the absolute value of x (integral value)
fabs(a,b); // Returns the absolute value of x (double)
sqrt(x);   // Returns the square root of x.
pow(base,exp); // Returns base raised to the power exp
ceil(x); // Rounds x upward, returning the smallest integral value that is not less than x
floor(x); // Rounds x downward, returning the largest integral value that is not greater than x
exp(x); // Returns the base-e exponential function of x, which is e raised to the power x
log(x); // Returns the natural logarithm of x
log2(x); // Returns the binary (base-2) logarithm of x
log10(x); // Returns the common (base-10) logarithm of x
modf(double x, double *intpart); /* Breaks x into an integral and a fractional part. The integer part is stored in the object
pointed by intpart, and the fractional part is returned by the function. Both parts have the same sign as x. */
sin(),cos(),tan(); asin(),acos(),atan(); sinh(),cosh(),tanh(); // Trigonometric functions
// See http://www.cplusplus.com/reference/cmath/ for more useful math functions!

Strings:
s.replace(pos,len,str); // Replaces the portion of the string that begins at character pos and spans len characters by str
s.replace(start,end,str); // or the part of the string in the range between [start,end)
s.substr(pos = 0,len = npos); // Returns the substring starting at character pos that spans len characters (or until the end of the string, whichever comes first).
// A value of string::npos indicates all characters until the end of the string.
s.insert(pos,str); // Inserts str right before the character indicated by pos
s.erase(pos = 0, len = npos); erase(first,last); erase(iterator p); // Erases part of the string
s.find(str,pos = 0); // Searches the string for the first occurrence of the sequence specified by its arguments after position pos
toupper(char x); // Converts lowercase letter to uppercase. If no such conversion is possible, the value returned is x unchanged.
tolower(char x); // Converts uppercase letter to lowercase. If no such conversion is possible, the value returned is x unchanged.

Constants:
INT_MAX, INT_MIN, LLONG_MIN, LLONG_MAX, ULLONG_MAX
const int maxn = 1e5; // 1e5 means 1x10^5, C++ features scientific notation. e.g.: 4.56e6 = 4.560.000, 7.67e-5 = 0.0000767.
const double pi = acos(-1); // Compute Pi

Algorithms:
swap(a,b); // Exchanges the values of a and b
minmax(a,b); // Returns a pair with the smallest of a and b as first element, and the largest as second.
minmax({1,2,3,4,5}); // Returns a pair with the smallest of all the elements in the list as first element and the largest as second
next_permutation(a,a+n); // Rearranges the elements in the range [first,last) into the next lexicographically greater permutation.
reverse(first,last); // Reverses the order of the elements in the range [first,last)
rotate(first,middle,last) // Rotates the order of the elements in the range [first,last), in such a way that the element pointed by middle becomes the new first element
remove_if(first,last,func) // Returns an iterator to the element that follows the last element not removed. The range between first and this iterator includes all the elements in the sequence for which func does not return true. 
// See http://www.cplusplus.com/reference/algorithm/ for more useful algorithms!

Binary search:
int a[] = {1, 2, 4, 7, 10, 12}, x = 5;     
int *l = lower_bound(a,a+6,x); // lower_bound: Returns the first element that is not less than x
cout << (l == a+5 ? -1 : *l) << endl;   
cout << x << (binary_search(a,a+6,x)?" is\n":" isn't\n"); // binary_search: Returns true if any element in the range [first,last) is equivalent to x, and false otherwise.
vi v(a,a+6);
auto i = upper_bound(v.begin(),v.end(),x) // upper_bound: Returns the first element that is greater than x

Random numbers: 
mt19937_64 rng(time(0)); //if TLE use 32 bits: mt19937
ll rnd(ll a, ll b) { return a + rng()%(b-a+1); }
Unhackable seed (Codeforces):
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
random_shuffle(a,a+n,rng); // Rearranges the elements in the range [first,last) randomly

Sorting:
sort(a,a+n,comp); /* Sorts the elements in the range [first,last) into ascending order. 
The third parameter is optional, if greater<Type> is passed then the array is sorted in descending order.
comp: Binary function that accepts two elements in the range as arguments, and returns a value convertible to bool. The value returned
indicates whether the element passed as first argument is considered to go before the second in the specific strict weak ordering
it defines. The function shall not modify any of its arguments. This can either be a function pointer or a function object. */
stable_sort(a,a+n); // Sorts the elements in the range [first,last) into ascending order, like sort, but stable_sort preserves the relative order of the elements with equivalent values.
sort(a.begin(),a.end()); // Sort using container ranges
sort(a,a+n,[](const node &a, const node &b){ // Custom sort with a "lambda expression": an unnamed function object capable of capturing variables in scope.
	return a.x < b.x || (a.x == b.x && a.y < b.y);   // Custom sort
}); // see https://en.cppreference.com/w/cpp/language/lambda for more details
bool myfunction(const edge &a, const edge &b){ return a.w < b.w; } 
sort(myvector.begin()+4, myvector.end(), myfunction); // Using a function as a comparator
struct comp{ bool operator()(const edge &a, const edge &b){ return a.w < b.w; } }; 
multiset<edge,comp> l; // Using a function object as comparator:
bool operator<(const edge &a, const edge &b){ return a.w < b.w; } // Operator definition (it can be inside or outside the class)

Input/output handling:
freopen("input.txt","r",stdin); // Sets the standard input stream (keyboard) to the file input.txt
freopen("output.txt","w",stdout); // Sets the standard output stream (screen) to the file output.txt
getline(cin,str); // Reads until an end of line is reached from the input stream into str. If we use cin >> str it would read until it finds a whitespace
// Make an extra call if we previously read another thing from the input stream (otherwise it wouldn't work as expected)
cout << fixed << setprecision(n); // Sets the decimal precision to be used to format floating-point values on output operations to n
cout << setw(n); // Sets the field width to be used on output operations to n
cout << setfill('0'); // Sets c as the stream's fill character

Increment stack size to the maximum (Linux):
// #include <sys/resource.h>
struct rlimit rl;
getrlimit(RLIMIT_STACK, &rl);
rl.rlim_cur = rl.rlim_max;
setrlimit(RLIMIT_STACK, &rl);

String to int and vice versa (might be very useful to parse odd things):
template <typename T> string to_str(T str) { stringstream s; s << str; return s.str(); }
template <typename T> int to_int(T n) { int r; stringstream s; s << n; s >> r; return r; }
C++11:
to_string(num) // returns a string with the representation of num
stoi,stoll,stod,stold // string to int,ll,double & long double respectively

Print structs with cout:
ostream& operator << (ostream &o, pto &p) {
    o << p.x << ' ' << p.y;
    return o;
}
