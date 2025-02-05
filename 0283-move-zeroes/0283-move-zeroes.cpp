class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 0 1 0 3 12
        if(nums.size()==1) return;
        int i=0;
        int j=0;
        int n = nums.size();
        while(i<n){
            if(nums[i]==0) break;
            i++; // i = 1
        }
        while(j<n){
            if(nums[j]!=0) break;
            j++; // j = 0
        }

        while(i<n && j<n){
            if(i<j) swap(nums[i],nums[j]);
           

            j++;
            

            while(j<n){
                if(nums[j]!=0) break;
                j++;
            }
            while(i<n){
                if(nums[i]==0) break;
                i++;
            }
        }

    }
};