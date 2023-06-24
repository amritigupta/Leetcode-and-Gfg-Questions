class Solution {
    
    int f (int ind, int prevind , vector<int> &nums, int &n, vector<vector<int>> &dp){
        if (ind == n){
            return 0;
        }
        if (dp[ind][prevind+1]!=-1){
            return dp[ind][prevind+1];
        }
            
        //prevind remains same
        int nottake = f(ind+1, prevind, nums , n,dp);
        
        int take = 0;
        
        //why not if(ind==0)
        // cuz first element can be ANY index not just 0th
        if ( prevind == -1 || nums[ind] > nums[prevind]) 
            //prevind is now changed to ind
            take = 1 + f(ind+1, ind, nums, n,dp);
        
        return dp[ind][prevind+1]= max(take, nottake);
        
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        return f(0,-1,nums,n,dp);
    }
    
    
//     // TABULATION
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        
//         for (int ind=n-1; ind>=0; ind--){
//             for(int prevind = ind-1; prevind>=-1; prevind--){
//                 int nottake = 0 + dp[ind+1][prevind+1];
                
//                 int take =0;
//                 if (prevind==-1 || nums[ind]>nums[prevind]){
//                     take = 1 + dp[ind+1][ind+1];
//                 }
                
//                 dp[ind][prevind+1]= max(take, nottake);
//             }
//         }
//         return dp[0][-1+1];
//     }
    
};