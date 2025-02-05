class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x1 = 0;
        for(int i=0; i<=n; i++){
            x1 ^= i;
        }
        
        int x2 = 0;
        for(int i=0; i<nums.size(); i++){
            x2^=nums[i];
        }

        return x1^x2;
        // 0 0 0
        // 0 0 1
        // 0 1 1 
        // 0 1 0

        // 0 0 0 


        // 0 1 0

    }
};