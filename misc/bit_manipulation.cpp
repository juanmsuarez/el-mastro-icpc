int setsz = 64;
string binary(ll x){
	string r = "";
	forn(i, setsz) 
        r += r & (1 << i) ? '1':'0';
    reverse(all(r));
	return r;
}
ll rightmost_bit(ll x) { return x & -x; }
ll leftmost_bit(ll x) { 63 - __builtin_clzll(x); } // lg(x)

bool pow_of_two(ll x) { return (x & (x-1)) == 0; }
bool pow_of_two_min_one(ll x){ return (x & (x+1)) == 0; }

x-th least significant bit (zero indexed):
void set_bit(ll _set, ll x){ _set |= 1LL << x; }
void clear_bit(ll _set, ll x){ _set &= ~(1LL << x); }
bool test_bit(ll _set, ll x){ return _set & (1LL << x); }
bool toggle_bit(ll _set, ll x){ return _set ^ (1LL << x); }

__builtin_clzll(x > 0), __builtin_ctzll(x > 0), __builtin_popcountll(x): 
count leading zeros, trailing zeros, and the number of 1-bits respectively for long long ints. 
Remove -ll from the end of the functions' names to use the versions for ints.

There are different bitwise operations used in the bit manipulation. These bit operations operate on the individual bits of the bit patterns.
Bit operations are fast and can be used in optimizing time complexity. The most common ones are  & (and), | (or), ~ (not) and ^ (xor). Their truth tables:

A 	B 	~A 	A & B  A | B  A ^ B
0 	0 	 1 	  0 	 0 	    0
0 	1 	 1    0 	 1 	    1
1 	0 	 0 	  0      1 	    1
1 	1 	 0 	  1  	 1 	    0 

e.g.: if A is 1010 and B is 1100, then A & B = 1000;   A | B = 1110;   A ^ B = 0110;   ~A = 11110101 (the number of 1′s depends on the type of A).

The other two operators we will need are the shift operators a << b and a >> b. The former shifts all the bits in a to the left by b positions; the latter does the same but shifts right. For non-negative values (which are the only ones we’re interested in), the newly exposed bits are filled with zeros. You can think of left-shifting by b as multiplication by 2^b and right-shifting as integer division by 2^b. 

Set operations:
We will use an integer to represent a set on a domain of up to 32 values (or 64, using a 64-bit integer), with a 1-bit representing a member that is present and a 0-bit one that is absent. ALL_BITS is a number with 1′s for all bits corresponding to the elements of the domain (-1 is represented this way).

Set union:        A | B
Set intersection: A & B
Set subtraction:  A & ~B
Set negation:     ALL_BITS ^ A
Set bit:          A |= 1 << bit
Clear bit:        A &= ~(1 << bit)
Test bit:         (A & (1 << bit)) != 0 
Toggle bit:        A ^= 1 << bit

Parity of x: (x & 1 ? "odd" : "even")

x modulo 2^k: x & ((1 << k)-1) (get last k bits)

Drop last bit in a mask: x & (x-1)
x & (x-1) will have all the bits equal to x except for the rightmost 1 in x, this is due to the fact that
x-1 has the rightmost bits (from the rightmost 1) flipped with regard to x. 

Get rightmost set bit in x: x & -x (or alternatively x ^ (x & (x-1)))
