class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt =0;
        while(n>0){
            int bit = n&1; //check if rightmost bit is 1 or 0
            if(bit) cnt++;
            n=n>>1;
        }
        return cnt;
    }
};