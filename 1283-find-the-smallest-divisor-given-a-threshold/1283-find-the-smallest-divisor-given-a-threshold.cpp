class Solution {
    bool ispos(int mid,vector<int>& nums, int t){
        int ans = 0;
        for(auto it: nums){
            ans+=ceil(double(it)/double(mid));
        }
        
        if(ans<=t){
            return true;
        }
        
        return false;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int ans = -1;
        
        
        while(l<=r){
            int mid = l+(r-l)/2;
            
            if(ispos(mid, nums, threshold)){
                ans = mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            
        }        
        return ans;
    }
};