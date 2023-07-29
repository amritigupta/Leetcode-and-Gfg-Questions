class Solution {
    //USING MEMOIZATION
// int f (int ind, int prevind , vector<int> &nums, int &n, vector<vector<int>> &dp){
//      if(ind==n){
//          return 0;
//      }
     
//      if(dp[ind][prevind+1]!=-1){
//          return dp[ind][prevind+1];
//      }
     
//      int len = 0+f(ind+1, prevind, nums, n, dp);
     
//      if(prevind==-1 || nums[prevind]<nums[ind]){
//          len = max(len, 1+f(ind+1, ind, nums, n, dp));
//      }
     
//      return dp[ind][prevind+1] = len;           
// }
    
// public:
// int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int> (n+1,-1));
//         return f(0,-1,nums,n,dp);
//   }
    
    
//     // A DIFFERENT SORT OF TABULATION  (INVOLVES LESS STEPS )
//     int lengthOfLIS(vector<int>& arr) {
//         int maxi=0;
//         int n = arr.size();
//         vector<int> dp(n+1, 1); //each element itself assigned 1 as it itself is LIS 
        
//         for(int i=0; i<n; i++){
//             for(int prev=0; prev<i; prev++){
//                 if(arr[prev] < arr[i]){
//                     dp[i]= max(dp[i], 1+dp[prev]);
//                }
//             }
            
//             maxi = max(dp[i] , maxi);
//         }
        
//         return maxi;
//     }
    
    // USING BINARY SEARCH
    public:
     int lengthOfLIS(vector<int>& arr) {
         int n = arr.size();
         vector<int> temp;
         temp.push_back(arr[0]);
         for(int i=1; i<n; i++){
             if(arr[i]>temp.back()){
                 temp.push_back(arr[i]);
             }
             else{
                 int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                 temp[ind]=arr[i];
             }
         }
         return temp.size();
     }
};