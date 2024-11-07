class Solution {
    int atmost(vector<int>& nums, int goal){
        int n = nums.size();
        int i=0, j=0;
        int sum=0;
        int ans=0;
        while(j<n){
            sum+=nums[j];
            while(sum>goal && i<=j){
                sum-=nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal)-atmost(nums, goal-1);
    }
};