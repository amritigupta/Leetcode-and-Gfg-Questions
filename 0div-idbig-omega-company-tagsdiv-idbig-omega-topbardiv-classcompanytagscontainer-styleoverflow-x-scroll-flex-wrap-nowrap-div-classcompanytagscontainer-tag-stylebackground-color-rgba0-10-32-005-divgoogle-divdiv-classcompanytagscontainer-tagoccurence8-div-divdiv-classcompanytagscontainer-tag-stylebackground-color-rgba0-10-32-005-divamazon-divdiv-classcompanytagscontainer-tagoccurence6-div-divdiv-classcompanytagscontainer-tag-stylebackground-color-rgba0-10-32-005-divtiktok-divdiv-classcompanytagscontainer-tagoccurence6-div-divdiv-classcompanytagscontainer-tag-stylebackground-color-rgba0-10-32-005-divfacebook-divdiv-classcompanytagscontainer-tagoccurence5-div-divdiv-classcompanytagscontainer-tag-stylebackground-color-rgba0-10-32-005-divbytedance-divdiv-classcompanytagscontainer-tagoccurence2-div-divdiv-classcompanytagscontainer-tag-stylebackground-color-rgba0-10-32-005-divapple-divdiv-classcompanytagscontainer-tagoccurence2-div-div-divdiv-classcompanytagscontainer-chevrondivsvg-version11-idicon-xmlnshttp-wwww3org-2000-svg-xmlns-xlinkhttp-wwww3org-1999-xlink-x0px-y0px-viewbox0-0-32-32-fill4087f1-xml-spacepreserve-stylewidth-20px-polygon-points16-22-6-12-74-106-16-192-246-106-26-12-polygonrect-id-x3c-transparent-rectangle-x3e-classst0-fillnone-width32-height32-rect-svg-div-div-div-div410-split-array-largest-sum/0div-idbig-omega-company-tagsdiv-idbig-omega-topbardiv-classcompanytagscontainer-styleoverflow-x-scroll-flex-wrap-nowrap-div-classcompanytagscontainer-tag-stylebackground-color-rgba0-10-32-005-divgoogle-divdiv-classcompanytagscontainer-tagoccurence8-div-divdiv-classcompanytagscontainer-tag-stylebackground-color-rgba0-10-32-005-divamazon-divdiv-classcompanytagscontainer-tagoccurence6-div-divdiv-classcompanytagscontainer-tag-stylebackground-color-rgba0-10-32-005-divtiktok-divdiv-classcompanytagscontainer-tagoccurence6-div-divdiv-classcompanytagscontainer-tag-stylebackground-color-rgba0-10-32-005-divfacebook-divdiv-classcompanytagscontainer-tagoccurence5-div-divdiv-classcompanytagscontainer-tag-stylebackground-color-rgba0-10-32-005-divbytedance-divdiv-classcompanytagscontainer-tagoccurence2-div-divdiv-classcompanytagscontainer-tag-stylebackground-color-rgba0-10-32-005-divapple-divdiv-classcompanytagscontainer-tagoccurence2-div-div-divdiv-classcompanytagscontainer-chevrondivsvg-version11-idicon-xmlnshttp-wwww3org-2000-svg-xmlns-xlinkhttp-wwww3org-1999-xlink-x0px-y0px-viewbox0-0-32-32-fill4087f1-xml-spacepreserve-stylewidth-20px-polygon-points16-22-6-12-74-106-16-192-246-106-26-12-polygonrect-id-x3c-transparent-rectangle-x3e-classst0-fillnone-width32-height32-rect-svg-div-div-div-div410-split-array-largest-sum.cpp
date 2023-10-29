class Solution {
    bool check(vector<int>& nums, int k, int mid){
        int count=1;
        int sum=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                count++;
                if(count>k){
                    return false;
                }
                sum=nums[i];
            }
        }
        
        return true;
    } 
public:
    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);
        int ans;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(check(nums, k, mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        return ans;
    }
};