class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int unique=1;
        //first element is always unique
        for(int i=1; i<n; i++){
            if(nums[i-1]!=nums[i]){ 
                nums[unique]=nums[i];
                unique++;
            }
        }

        return unique;
    }
};