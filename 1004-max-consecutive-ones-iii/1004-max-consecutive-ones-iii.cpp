class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int i=0;
        int j=0;
        int n = nums.size();
        int maxi = 0;
        while(j<n){
            if(nums[j]==0) zeros++;
            while(zeros>k){
                if(nums[i]==0) zeros--;
                i++;
            }
            maxi=max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};