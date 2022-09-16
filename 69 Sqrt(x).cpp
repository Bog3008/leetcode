// очень важга точность сравнения в while
class Solution {
public:
int mySqrt(int x) {
    double R = x, L = 0;
    double M;
    while(R - L > 1e-9){
        M = (R + L) / 2;
        if(M*M < x)
            L = M;
        else
            R = M;
    }
    return(R);
}
};
