class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        // k is 3
        // m > logk
        // m is 2

        int x1=0;
        int x2=0;

        // bitwise operations count from 0 to 2^m-1
        // 0 to 2^2-1 = 3
        // k is also 3
        // we need a mask then (as k is not less than 2^m-1)

        // k = 3 --> 1 1 --> mask = ~(x1 & x2)
        // if k was 5 --> 1 0 1 --> mask = ~(x1&(~x2)&x3)

        for(auto i : nums){
            x2^=(x1&i);
            x1^=i;

            int mask = ~(x1&x2);

            x2&=mask;
            x1&=mask;
        }

        return (x1|x2);
    }
};