class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int, vector<int>> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(nums[i]+nums[j]==target){
                if(nums[i]==nums[j]){
                    v.push_back(mpp[nums[i]][0]);
                    v.push_back(mpp[nums[i]][1]);
                }
                else{
                  v.push_back(mpp[nums[i]][0]);
                  v.push_back(mpp[nums[j]][0]);
                }
                return v;
            }
            else if(nums[i]+nums[j]>target){
                j--;
            }
            else{
                i++;
            }
        }

        return v;
    }
};