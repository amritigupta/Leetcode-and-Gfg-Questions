class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int s=0;
        int maxi=0;
        int i=0;
        while(i<nums.size()){
            if(i!=nums.size()-1 && nums[i]<nums[i+1]){
                s+=nums[i];
                i++;
            }
            else{
                s+=nums[i];
                maxi=max(maxi, s);
                s=0;
                i++;
            }
        }

        return maxi;
    }
};