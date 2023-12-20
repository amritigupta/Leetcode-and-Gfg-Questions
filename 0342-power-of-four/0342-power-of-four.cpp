#include<cmath>

class Solution {
public:
    bool isPowerOfFour(int n) {
        
        double f = log2(n);
        
        // log 16 = 4
        // log 20 = 
        // log 4 = 2
        // log 64 = 6
        
        if(n<4){
            if(n==1){
                return true;
            }
            else{
                return false;
            }
        }
        
        if((n&(n-1))==0 && int(f)%2==0  ){
            return 1;
        }
        else{
            return 0;
        }
    }
};