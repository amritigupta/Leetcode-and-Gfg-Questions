class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int i=0, j=0, maxcount=0;
    int n = nums.size();
    while(j<n){
        
        if(nums[j] == 0){
            i = j+1;
        }
        
        maxcount = max(maxcount, j-i+1);
        j++;
    }
   return maxcount; 
    }
};