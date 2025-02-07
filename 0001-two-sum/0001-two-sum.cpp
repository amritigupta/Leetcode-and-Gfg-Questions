class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
                v={mpp[target-nums[i]], i};
                break;
            }
            mpp[nums[i]]=i;
        }
        return v;
    }
};