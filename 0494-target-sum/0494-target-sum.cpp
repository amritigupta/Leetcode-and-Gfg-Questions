class Solution {
    int f (vector<int> &nums, int target, int ind, vector<vector<int>> &dp){
        if (ind==0){ // BASE CASES
            
            if (target==0 && nums[0]==0){
                return 2; //pick or notpick
            }
            else if(target==0 && nums[0]!=0){
                return 1; //notpick
            }
            else if(nums[0]!=0 && target==nums[0]){
                return 1; //pick
            }
            else{
                return 0;
            }
            
        }
        
        if (dp[ind][target]!=-1){
            return dp[ind][target];
        }
        
        int nottake = 0+f(nums,target,ind-1,dp);
        int take = 0;
        if (nums[ind]<=target){
            take= f(nums, target-nums[ind], ind-1, dp);
        }
        
        return dp[ind][target]= take+nottake;
        
        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totsum=0;
        for (int i=0; i<n; i++){
            totsum+=nums[i];
        }
        
        if (totsum-target<0 || (totsum-target)%2){
            return 0;
        }
        int S = (totsum-target)/2;
        vector<vector<int>> dp(n, vector<int> (S+1,-1));
        
        return f(nums, S, n-1, dp);
    }
};