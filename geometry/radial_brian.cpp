#define buenas(P) (P.y < 0 || (P.y == 0 && P.x < 0)) // True if angle >=180
dot C; // Store the center in C
bool radial(dot a, dot b){
    a = a-C; b = b-C;
    if(buenas(a) ^ buenas(b))return buenas(b);
    if((a^b) == 0)return a.norm_sq() < b.norm_sq(); //Adjust this case to define an order for those in the same angle or in the center
    //Note that for points at the same angle, this code puts closer to the center first
    //Note that if a point is at the center this code puts it very first
    return (a^b) > 0;
}
