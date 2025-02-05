class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        int maxi=0;

        while(i<n){
            if(nums[i]!=1){
                while(i<n){
                    if(nums[i]==1)break;
                    i++; //st point 
                }
            }
            j=i;
            while(j<n){
                if(nums[j]==1) j++;
                else break;
            }
            maxi=max(j-i, maxi);
            // at this point j is not 1 , it is 0
            //put i at j
            i=j;
        }

        return maxi;
    }
};