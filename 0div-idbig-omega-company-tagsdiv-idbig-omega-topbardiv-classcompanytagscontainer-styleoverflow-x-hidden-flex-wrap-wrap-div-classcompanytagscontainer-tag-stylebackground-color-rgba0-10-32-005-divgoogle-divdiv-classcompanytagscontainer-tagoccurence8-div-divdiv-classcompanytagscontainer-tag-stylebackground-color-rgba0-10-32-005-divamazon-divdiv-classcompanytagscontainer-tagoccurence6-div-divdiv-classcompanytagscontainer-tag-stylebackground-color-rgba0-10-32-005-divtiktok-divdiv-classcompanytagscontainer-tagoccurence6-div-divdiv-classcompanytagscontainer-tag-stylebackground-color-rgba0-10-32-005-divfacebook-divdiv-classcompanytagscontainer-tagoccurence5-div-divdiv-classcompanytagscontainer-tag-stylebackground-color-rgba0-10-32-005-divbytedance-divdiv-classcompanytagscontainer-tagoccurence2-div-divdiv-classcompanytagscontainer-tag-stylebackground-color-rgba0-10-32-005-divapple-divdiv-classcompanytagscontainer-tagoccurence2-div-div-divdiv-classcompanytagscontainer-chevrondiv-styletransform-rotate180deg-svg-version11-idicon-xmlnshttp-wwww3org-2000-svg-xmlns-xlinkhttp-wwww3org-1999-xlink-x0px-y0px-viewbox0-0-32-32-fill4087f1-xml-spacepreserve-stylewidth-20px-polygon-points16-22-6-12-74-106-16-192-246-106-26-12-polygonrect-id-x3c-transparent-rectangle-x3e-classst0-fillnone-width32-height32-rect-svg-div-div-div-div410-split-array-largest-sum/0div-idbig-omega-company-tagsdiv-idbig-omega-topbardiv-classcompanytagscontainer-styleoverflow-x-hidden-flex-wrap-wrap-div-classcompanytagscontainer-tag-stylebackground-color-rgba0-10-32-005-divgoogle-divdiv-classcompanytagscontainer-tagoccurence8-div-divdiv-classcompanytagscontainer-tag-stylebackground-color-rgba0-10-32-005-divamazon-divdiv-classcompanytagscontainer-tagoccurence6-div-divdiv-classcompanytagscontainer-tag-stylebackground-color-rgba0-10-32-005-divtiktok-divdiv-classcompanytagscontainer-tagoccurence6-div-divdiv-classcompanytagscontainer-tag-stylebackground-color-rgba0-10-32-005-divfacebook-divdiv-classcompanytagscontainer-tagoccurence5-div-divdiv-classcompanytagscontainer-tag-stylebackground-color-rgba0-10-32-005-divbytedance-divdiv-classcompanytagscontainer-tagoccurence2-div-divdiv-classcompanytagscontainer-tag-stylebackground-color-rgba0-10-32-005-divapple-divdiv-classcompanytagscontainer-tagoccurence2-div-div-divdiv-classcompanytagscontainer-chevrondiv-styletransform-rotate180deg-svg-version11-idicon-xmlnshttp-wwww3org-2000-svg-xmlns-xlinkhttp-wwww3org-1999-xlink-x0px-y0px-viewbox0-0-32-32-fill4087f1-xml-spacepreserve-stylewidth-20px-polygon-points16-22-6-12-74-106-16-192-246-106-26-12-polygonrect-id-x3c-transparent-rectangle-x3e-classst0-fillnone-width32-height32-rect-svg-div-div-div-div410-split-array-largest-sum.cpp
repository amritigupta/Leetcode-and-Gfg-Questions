class Solution {
public:
    bool check(vector<int>&nums, int threshold,int tar){
       int coun = 1;
       int sum = 0;
       for(int i=0;i<nums.size();i++){
           sum += nums[i];
           if(sum > threshold){
               sum = nums[i];
               coun++;
           }
           if(coun > tar) return false;
       } 
       return true;
    }
   
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end()); //start
        int high = accumulate(nums.begin(),nums.end(),0); //end
        int ans ;
        while(low <= high){
            int mid = (low+high)/2; //mid
            if(check(nums,mid,k)){
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};