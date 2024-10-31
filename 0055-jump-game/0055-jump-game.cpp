class Solution {
    bool f(int idx, vector<int>& nums, int n, vector<int> &dp){
        if(idx>=n-1) return true;
        
        if(dp[idx]!=-1) return dp[idx];

        int maxjump = nums[idx];

        for(int i=1; i<=maxjump; i++){
            if(f(idx+i, nums, n, dp)==true){
                dp[idx]=true;
                return true;
            }
        }

        dp[idx]=false;
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, n, dp);
    }
};