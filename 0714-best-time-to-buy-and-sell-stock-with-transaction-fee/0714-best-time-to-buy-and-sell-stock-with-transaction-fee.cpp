class Solution {
    int f (int ind, int buy, int &fee,vector<int>& prices, int &n , vector<vector<int>> &dp){
        if (ind==n){
            return 0;
        }
        
        if (dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int profit =0;
        if(buy){
            profit = max(-prices[ind]+f(ind+1,0,fee,prices,n,dp), 0+f(ind+1,1,fee,prices,n,dp));
        }
        else{
            profit = max(prices[ind]-fee+f(ind+1,1,fee,prices,n,dp) , 0+f(ind+1,0,fee,prices,n,dp));
        }
        return dp[ind][buy]= profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return f (0,1,fee,prices,n, dp);
    }
};