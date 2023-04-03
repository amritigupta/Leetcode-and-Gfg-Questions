class Solution {
    int f (int ind, int T, vector<int> &nums,  vector<vector<int>> &dp){
        if (ind==0){ //base case
            if(T%nums[0]==0){
                return T/nums[0];
            }
            else{
                return 1e7;
            }
        } 
        
        if (dp[ind][T]!=-1){
            return dp[ind][T];
        }
        
        int nottake = 0+f(ind-1,T,nums, dp);
        int take = INT_MAX;
        if (nums[ind]<=T){
            take = 1 + f(ind, T-nums[ind], nums, dp);
        }
        
        return dp[ind][T]=min(take, nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = f (n-1, amount, coins, dp);
        
        if (ans >=1e7){
            return -1;
        }
        else{
            return ans;
        }
    }
};