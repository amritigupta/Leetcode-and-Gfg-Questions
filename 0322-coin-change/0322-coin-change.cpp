class Solution {
    int f(int ind , int amount, vector<int>& coins, vector<vector<int>> &dp){
        if(ind==0){
            if(coins[ind]==amount){
                return 1;
            }
            if(amount%coins[ind] == 0){
                return amount/coins[ind];
            }
            return 1e7;
        }
        
        if(dp[ind][amount] !=-1){
            return dp[ind][amount];
        }
        
        int nottake = f(ind-1, amount, coins, dp);
        int take = 1e7;
        if(coins[ind]<=amount){
            take = 1+ f(ind, amount-coins[ind],coins, dp);
        }
        int take2 = INT_MAX;
        
        return dp[ind][amount] = min(nottake, take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1 , -1));
        int ans = f(n-1, amount, coins, dp);

        if(ans>=1e7){
            return -1;
        }
        return ans;
    }
};