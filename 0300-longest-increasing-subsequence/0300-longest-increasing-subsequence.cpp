class Solution {
    int f (int ind, int prevind , vector<int> &nums, int &n, vector<vector<int>> &dp){
        if (ind == n){
            return 0;
        }
        if (dp[ind][prevind+1]!=-1){
            return dp[ind][prevind+1];
        }
            
            
        int nottake = f(ind+1, prevind, nums , n,dp);
        int take = 0;
        if (prevind == -1 || nums[ind] > nums[prevind]) take = 1 + f(ind+1, ind, nums, n,dp);
        
        return dp[ind][prevind+1]= max(take, nottake);
        
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        return f(0,-1,nums,n,dp);
    }
};