class Solution {
    int f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(ind==0){
            if (target == 0 && nums[0]==0) return 2;
            else if(target == 0 || nums[0] == target) return 1;
            else return 0;
        }
        
        if(dp[ind][target] !=-1){
            return dp[ind][target];
        }
        
        int nottake = f(ind-1, target, nums, dp);
        int take =0;
        if(target-nums[ind]>=0){
            take = f(ind-1, target-nums[ind], nums, dp);
        }
        return dp[ind][target] = (take+nottake);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // divide into 2 subsets such that s1 - s2 = target 
        
        // s1 - s2 = target
        // totsum - 2s1 = target
        // s1 = (totsum - target)/2
        
        int n = nums.size();
        int totsum = 0;
        for(auto it: nums){
            totsum+= it;
        }
        if(totsum - target < 0 || (totsum-target)%2 == 1){
            return 0;
        }
        int s = (totsum-target)/2;
        vector<vector<int>> dp(n+1, vector<int>(s+1, -1));
        
        return f(n-1, s, nums, dp);
    }
};