class Solution {
//     int f (int ind, int buy, vector<int> &arr, int n, vector<vector<int>> &dp){
        
//         if (ind == n){
//             return 0; //no more profit
//         }
//         if(dp[ind][buy]!=-1){
//             return dp[ind][buy];
//         }
//         int profit = 0;
//         if (buy){
//             profit = max(-arr[ind]+ f(ind+1, 0, arr, n,dp), 0+f(ind+1, 1, arr, n,dp));
//         }
//         else{
//             profit = max(arr[ind]+f(ind+1, 1,arr,n,dp), 0 + f(ind+1, 0, arr, n,dp));
//         }
//         return dp[ind][buy] = profit;
//     }
public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
        
//         vector<vector<int>> dp(n, vector<int> (2,-1));
//         return f(0, 1, prices, n, dp);
//     }
    
  int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int> (2,0));
        dp[n][0]= dp[n][1]=0;
      
        for (int ind = n-1; ind>=0 ; ind--){
            for (int buy = 0; buy<=1; buy++){
                if (buy){
                    dp[ind][buy] = max(-prices[ind]+dp[ind+1][0], 0+dp[ind+1][1]);
                }
                else{
                    dp[ind][buy] = max(prices[ind]+dp[ind+1][1], 0+dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};