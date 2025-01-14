class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> mpp;
        for(int i=0; i<n; i++){
            if(mpp.find(nums[i])!=mpp.end()){
                return true;
            }
            mpp[nums[i]]=1;
        }
        return false;
    }
};