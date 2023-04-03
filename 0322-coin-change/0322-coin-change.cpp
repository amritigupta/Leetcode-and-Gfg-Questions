class Solution {
//     int f (int ind, int T, vector<int> &nums,  vector<vector<int>> &dp){
//         if (ind==0){ //base case
//             if(T%nums[0]==0){
//                 return T/nums[0];
//             }
//             else{
//                 return 1e7;
//             }
//         } 
        
//         if (dp[ind][T]!=-1){
//             return dp[ind][T];
//         }
        
//         int nottake = 0+f(ind-1,T,nums, dp);
//         int take = INT_MAX;
//         if (nums[ind]<=T){
//             take = 1 + f(ind, T-nums[ind], nums, dp);
//         }
        
//         return dp[ind][T]=min(take, nottake);
//     }
public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int> (amount+1, -1));
//         int ans = f (n-1, amount, coins, dp);
        
//         if (ans >=1e7){
//             return -1;
//         }
//         else{
//             return ans;
//         }
//     }
    
    
    // TABULATION

int coinChange(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
}
};