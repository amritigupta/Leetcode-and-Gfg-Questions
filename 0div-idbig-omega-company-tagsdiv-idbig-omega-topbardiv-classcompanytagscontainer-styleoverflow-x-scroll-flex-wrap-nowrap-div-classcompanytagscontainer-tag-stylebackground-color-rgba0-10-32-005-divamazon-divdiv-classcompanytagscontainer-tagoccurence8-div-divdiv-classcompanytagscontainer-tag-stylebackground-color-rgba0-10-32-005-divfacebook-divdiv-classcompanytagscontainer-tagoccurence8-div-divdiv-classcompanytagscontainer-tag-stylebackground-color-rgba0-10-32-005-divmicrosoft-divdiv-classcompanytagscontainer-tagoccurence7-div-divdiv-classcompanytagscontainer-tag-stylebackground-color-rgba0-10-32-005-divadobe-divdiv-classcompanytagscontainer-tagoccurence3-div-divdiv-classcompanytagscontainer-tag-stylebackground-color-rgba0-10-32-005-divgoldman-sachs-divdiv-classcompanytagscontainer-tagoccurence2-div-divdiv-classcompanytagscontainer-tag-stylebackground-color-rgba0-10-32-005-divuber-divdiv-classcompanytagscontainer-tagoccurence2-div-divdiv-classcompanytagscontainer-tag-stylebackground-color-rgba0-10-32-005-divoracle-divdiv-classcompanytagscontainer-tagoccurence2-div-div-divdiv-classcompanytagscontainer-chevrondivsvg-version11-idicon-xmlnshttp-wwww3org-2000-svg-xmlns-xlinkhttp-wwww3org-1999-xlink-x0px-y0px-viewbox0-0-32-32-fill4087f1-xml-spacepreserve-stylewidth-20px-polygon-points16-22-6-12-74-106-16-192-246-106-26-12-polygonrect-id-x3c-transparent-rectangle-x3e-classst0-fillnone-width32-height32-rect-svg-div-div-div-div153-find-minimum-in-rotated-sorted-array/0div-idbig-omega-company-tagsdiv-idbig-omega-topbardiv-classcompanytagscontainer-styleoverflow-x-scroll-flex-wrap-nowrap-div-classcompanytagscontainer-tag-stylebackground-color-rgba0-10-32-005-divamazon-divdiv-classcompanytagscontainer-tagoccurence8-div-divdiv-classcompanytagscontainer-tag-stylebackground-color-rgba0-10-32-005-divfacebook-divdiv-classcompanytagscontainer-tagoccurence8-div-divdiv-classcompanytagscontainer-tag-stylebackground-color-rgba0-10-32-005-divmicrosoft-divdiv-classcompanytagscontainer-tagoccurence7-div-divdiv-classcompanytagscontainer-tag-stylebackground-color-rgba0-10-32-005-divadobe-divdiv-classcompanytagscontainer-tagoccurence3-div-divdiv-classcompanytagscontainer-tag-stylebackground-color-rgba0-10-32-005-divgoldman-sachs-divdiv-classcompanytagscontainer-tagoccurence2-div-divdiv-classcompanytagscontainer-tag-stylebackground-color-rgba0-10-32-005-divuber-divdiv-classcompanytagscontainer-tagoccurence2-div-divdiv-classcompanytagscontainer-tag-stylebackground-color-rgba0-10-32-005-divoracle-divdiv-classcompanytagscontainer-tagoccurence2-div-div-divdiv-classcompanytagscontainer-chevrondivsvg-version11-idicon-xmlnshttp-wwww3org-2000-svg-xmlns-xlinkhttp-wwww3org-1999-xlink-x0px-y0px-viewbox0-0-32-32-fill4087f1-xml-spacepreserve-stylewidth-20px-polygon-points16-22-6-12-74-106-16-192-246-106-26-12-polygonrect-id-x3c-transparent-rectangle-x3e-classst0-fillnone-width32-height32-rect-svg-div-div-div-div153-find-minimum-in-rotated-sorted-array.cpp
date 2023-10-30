class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int n = nums.size(); // 5 
        if(n==1){
            return nums[0];
        }
        int high = n-1; // 4
        if(nums[0]<nums[n-1]){ //non rotated array
            return nums[0];
        }
        
        // 0 1 2 3 4 5 6
        // 4 5 6 7 0 1 2
        
        // mid = 3
        // low = 4
        // high = 6
        
        // mid = 5
        
        
        while(low<=high){
            int mid = (low+high)/2; // 3
            if(nums[mid]<nums[(mid+1)%n] && nums[mid]<nums[(mid-1)]){
                return nums[mid];
            }
            else if(nums[high]>nums[mid]){ //right half is sorted
                high = (mid-1);
            }
            else{
                low = (mid+1);
            }
        }
        
        return -1;
    }
};