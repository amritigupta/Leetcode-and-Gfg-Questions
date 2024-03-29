class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int e = nums.size();
        // Checking the boundary first
        if(e == 1){
            return nums[0];
        }
        
        if(nums[0] != nums[1]){
            return nums[0];
        }
        
        if(nums[e-1] != nums[e-2]){
            return nums[e-1];
        }
        
        int s = 0;
        int mid = s + (e - s) / 2;
        int ans = -1;
        
        while(s <= e){
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                ans = nums[mid];
                break;
            }
            // check if it is left half or right half
            else if((nums[mid] == nums[mid+1] && mid % 2 == 0) || (mid % 2 == 1 && nums[mid] == nums[mid-1])){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            
            mid = s + (e - s) / 2;
        }
        
        return ans;
    }
};