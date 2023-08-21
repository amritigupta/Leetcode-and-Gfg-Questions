
class Solution {
public:
//     int maxSubArray(vector<int>& nums) {
//         int start = 0, sum = 0, max = INT_MIN, n = nums.size();
        
//         for(int end = 0; end < n; end++) {
//             sum += nums[end];   
//             if(sum > max) max = sum;
//             while(sum < 0) 
//                 sum -= nums[start++];
//         }
        
//         return max;
//     }
    
     int maxSubArray(vector<int>& nums) {
         int n = nums.size();
         int sum=0;
         int maxi=INT_MIN;
         for(int i=0; i<n; i++){
             sum+=nums[i];
            
             maxi=max(maxi, sum);
              if(sum<0){sum=0;}
         }

         return maxi;
     }
};