class Solution {
    
    int f(int ind, vector<int> &dp , vector<int> &a){
        if(ind < 0 ){
            return 0;
        }
        if(ind==0){
            return a[ind];
        }
        
        
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        int pick = a[ind] + f(ind-2, dp, a);
        int notpick = 0 + f(ind-1, dp, a);
        
        return dp[ind] = max(pick, notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return f(n-1, dp, nums);
    }
};