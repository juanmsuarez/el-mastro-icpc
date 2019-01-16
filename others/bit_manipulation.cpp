#include <bits/stdc++.h> 
using namespace std;

ll myset = 0, setsz = 32;

string binary(ll x){
	string r = "";
	forn(i,setsz){
	    r = (x&1?'1':'0') + r; 
	    x >>= 1;
	}
	return r;
}
void set_bit(ll x){
	myset |= 1 << (x-1);
}
void clear_bit(ll x){
	myset &= ~(1 << (x-1));
}
bool test_bit(ll x){
	return myset & (1 << (x-1));
}
bool pow_of_two(ll x){
	return x & (x-1) == 0;
}

int main() {
	cout << "Enter a integer number: ";
    ll n; cin >> n;
	cout << '\n';
	cout << "Binary:       "   << binary(n)      << '\n';
	cout << "Left shift:   "   << binary(n << 1) << '\n';
	cout << "Right shift:  "   << binary(n >> 1) << '\n';
	cout << "Set negation: "   << binary(~n)     << '\n';
	cout << n << " is " << (n&1?("odd"):("even")) << '\n'; 
	cout << n << " has " << __builtin_popcount(n) << " 1-bits\n\n";

	ll t; cin >> t;
	while(t--){
		cin >> n; 
		char o; cin >> o;
		if(o == 's'){
			set_bit(n);
			cout << binary(myset) << '\n';
		}
		else if(o == 'c'){
			clear_bit(n);
			cout << binary(myset) << '\n';
		}
		else if(o == 't') 
			cout << n << (test_bit(n)?(" is"):(" isn't")) << " in the set\n";
	}
	return 0;
}

/*
Test case:
157

14
3  s
13 s
10 s
2  s
16 s
2  t
13 c
5  t
10 t
3  c
3  t
1  t
16 t
11 s

-----------------------------------------------------------------------------------------------------------------------------

GCC built-in functions about bit manipulation:
int __builtin_clz (unsigned int x)
Returns the number of leading 0-bits in x, starting at the most significant bit position. If x is 0, the result is undefined. 
int __builtin_ctz (unsigned int x) 
Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined. 
int __builtin_popcount (unsigned int x) Returns the number of 1-bits in x. 
int __builtin_clzll (unsigned long long) Similar to __builtin_clz, except the argument type is unsigned long long. 
int __builtin_ctzll (unsigned long long) Similar to __builtin_ctz, except the argument type is unsigned long long. 

-----------------------------------------------------------------------------------------------------------------------------

At the heart of bit manipulation are the bit-wise operators & (and), | (or), ~ (not) and ^ (xor). 
The first three you should already be familiar with in their boolean forms (&&, || and !). 
As a reminder, here are the truth tables:

A 	B 	!A 	A && B 	A || B 	A ^ B
0 	0 	 1 	   0 	   0 	  0
0 	1 	 1     0 	   1 	  1
1 	0 	 0 	   0       1 	  1
1 	1 	 0 	   1  	   1 	  0 

The bit-wise versions of the operations are the same, except that instead of interpreting their arguments as true or false,
they operate on each bit of the arguments. Thus, if A is 1010 and B is 1100, then
A & B = 1000;   A | B = 1110;   A ^ B = 0110;   ~A = 11110101 (the number of 1′s depends on the type of A).

The other two operators we will need are the shift operators a << b and a >> b. The former shifts all the bits in 
a to the left by b positions; the latter does the same but shifts right. For non-negative values (which are the 
only ones we’re interested in), the newly exposed bits are filled with zeros. You can think of left-shifting by b
as multiplication by 2^b and right-shifting as integer division by 2^b. 

Set operations:
We will use an integer to represent a set on a domain of up to 32 values (or 64, using a 64-bit integer),
with a 1-bit representing a member that is present and a 0-bit one that is absent. 
ALL_BITS is a number with 1′s for all bits corresponding to the elements of the domain (-1 is represented this way).

Set union:        A | B
Set intersection: A & B
Set subtraction:  A & ~B
Set negation:     ALL_BITS ^ A (or ~A)
Set bit:          A |= 1 << bit
Clear bit:        A &= ~(1 << bit)
Test bit:         (A & 1 << bit) != 0 

-----------------------------------------------------------------------------------------------------------------------------

You can test if a positive integer n is a power of 2 with: (n & (n-1)) == 0 

If n can be non-positive (i.e. negative or zero) you should use
n > 0 && (n & (n-1)) == 0

If n is truly a power of 2, then in binary it will look like: 10000000...
so n-1 looks like: 0111111

and when we bitwise-AND them:
  10000000...
& 01111111...
  -----------
  00000000...

Now, if n isn't a power of 2, then its binary representation will have some other 1s in addition to 
the leading 1, which means that both n and n-1 will have the same leading 1 bit (since subtracting 
1 cannot possibly turn off this bit if there is another 1 in the binary representation somewhere). 
Hence the & operation cannot produce 0 if n is not a power of 2, since &ing the two leading bits of n 
and n-1 will produce 1 in and of itself. This of course assumes that n is positive.

*/