#include<cmath>

class Solution {
public:
    bool isPowerOfFour(int n) {
        
        double f = log2(n);
        if(n<4){
            if(n==1){
                return true;
            }
            else{
                return false;
            }
        }
        if(int(f)%2==0 && f==ceil(f) && f==floor(f) && (n&(n-1))==0){
            return 1;
        }
        else{
            return 0;
        }
    }
};