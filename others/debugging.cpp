#pragma GCC optimize ("trapv")//RTEs the program on integer overﬂows (really slow).
cin.exceptions(cin.failbit); //input error causes RTE

#ifdef LOCAL
    #define Dx(a) cerr << #a << " = " << (a)
    #define Dy(a)  Dx(a) << " , "
    #define D(a) Dx(a) << endl
    #define SEP cerr << " ================ " << endl
    #define LINE cerr << __LINE__ << endl
    #define trace(args...) { string  _s =#args; replace(_s.begin(), _s.end(), ',',' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);}
#else 
    #define D(a) 8 
    #define Dy(a) 8 
    #define trace 8
    #define SEP 8
#endif

void err(istream_iterator<string> it){}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args){
  cerr <<  *it  << " : " << a << endl;
  err(++it, args...);
}

template <typename T>
ostream & operator <<(ostream &os, const vector<T>&v){
    forn(i,v.size()){
        os << "[,"[i!=0];
        os << v[i];
    }
    return os<<"]";
}

/* recursion depth counter
 * f(int x,int z=0)
 *  cerr << strint(z,'\t');D(x);
 *  f(x,z+1)
 */
