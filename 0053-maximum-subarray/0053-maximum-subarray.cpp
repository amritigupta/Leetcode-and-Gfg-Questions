
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start = 0, sum = 0, max = INT_MIN, n = nums.size();
        
        for(int end = 0; end < n; end++) {
            sum += nums[end];   
            if(sum > max) max = sum;
            while(sum < 0) 
                sum -= nums[start++];
        }
        return max;
    }
};