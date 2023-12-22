class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
//         5 -> 1 0 1
//         6 -> 1 1 0
//         7 -> 1 1 1
        

            
        
        int count=0;
        while(left!=right){
            left>>=1;
            right>>=1;
            count++; //counts how many bits r not equal(so these bits shall be 0 from left)
        }
            
        return left<<=count;
        
    }
};