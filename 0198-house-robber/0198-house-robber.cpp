class Solution {
    int help(int ind, vector<int> &nums, vector<int> &dp ){
        if(ind>nums.size()-1){
            return 0;
        }
        if(ind==nums.size()-1){
            return nums[nums.size()-1];
        }
        
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        //u rob this index
        int ans1 = nums[ind] + help(ind+2, nums, dp) ;
        //u dont rob this index
        int ans2 = help(ind+1, nums, dp);
        
        return dp[ind]=max(ans1,ans2);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        int ans = help(0, nums, dp);
        return ans;
    }
};