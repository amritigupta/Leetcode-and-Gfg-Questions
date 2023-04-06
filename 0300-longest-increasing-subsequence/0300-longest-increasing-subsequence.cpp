class Solution {
//     int f (int ind, int prevind , vector<int> &nums, int &n, vector<vector<int>> &dp){
//         if (ind == n){
//             return 0;
//         }
//         if (dp[ind][prevind+1]!=-1){
//             return dp[ind][prevind+1];
//         }
            
            
//         int nottake = f(ind+1, prevind, nums , n,dp);
//         int take = 0;
//         if (prevind == -1 || nums[ind] > nums[prevind]) take = 1 + f(ind+1, ind, nums, n,dp);
        
//         return dp[ind][prevind+1]= max(take, nottake);
        
//     }
public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int> (n+1,-1));
//         return f(0,-1,nums,n,dp);
//     }
    
    
    
//// TABULATION
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
    

    
     // int lengthOfLIS(vector<int>& arr) {
     //     int n = arr.size();
     //     vector<int> dp(n,1);
     //     int maxi=1;
     //     for (int i=0; i<n ;i++){
     //         for(int prev=0; prev<i; prev++){
     //             if(arr[prev]<arr[i]){
     //                 dp[i]= max(dp[i], 1+dp[prev]);
     //             }
     //         }
     //         maxi= max(maxi,dp[i]);
     //     }
     //     return maxi;
     // }
    
    
 ///// PRINTING LIS
    
 
//    int lengthOfLIS(vector<int>& arr){

//          int n = arr.size();
//          int maxindex = 0;
//          vector<int> dp(n,1);
//          int maxi=1;
//          for (int i=0; i<n ;i++){
        
//              for(int prev=0; prev<i; prev++){
//                  if(arr[prev]<arr[i]){
//                      dp[i]= max(dp[i], 1+dp[prev]);
//                  }
//              }
//              if (dp[i]>maxi){
//                  maxi = dp[i];
//                  maxindex = i;
//              }
//          }
    
//          vector<int> ans;
//          ans.push_back(dp[maxindex]);
//          maxi--;
    
//     for (int i=0; i<n ; i++){
//         if(maxi==0){
//             break;
//         }
//         if (dp[i]==maxi){
//             ans.push_back(dp[i]);
//             maxi--;
//             continue;
//         }
//     }
//     for (auto it: ans){
//         cout<<it<<" ";
//     }
//     cout<<endl;
 
//    return maxi;
//    }
    
    //SOLVING BY BINARY SEARCH
     int lengthOfLIS(vector<int>& arr){
         vector<int> temp;
         int n = arr.size();
         
         temp.push_back(arr[0]);
         for(int i=1; i<n; i++){
             if (arr[i]>temp.back()){
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