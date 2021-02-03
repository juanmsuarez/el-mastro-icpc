// Reads integers very fast loading big chunks of the input into memory
const int BUF = 1 << 18;
char buf[BUF], *ibuf = buf, *lbuf = buf + BUF; 
template<typename T> inline void in(T& x){
    bool flg = 0; x = 0;
	while (!isdigit(*ibuf)) {
        if (*ibuf == '-') flg = 1;
        if (++ibuf == lbuf) fread(buf, 1, BUF, stdin), ibuf = buf;
    }
	while (isdigit(*ibuf)) {
        x = x*10 + (*ibuf ^ 48);
        if (++ibuf == lbuf) fread(buf, 1, BUF, stdin), ibuf = buf;
    }
    if (flg) x = -x;
}
