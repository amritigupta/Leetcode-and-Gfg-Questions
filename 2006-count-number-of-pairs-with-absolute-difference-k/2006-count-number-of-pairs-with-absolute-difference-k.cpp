class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            if(mpp.find(nums[i]-k)!=mpp.end()){
                ans+=mpp[nums[i]-k];
            }
            if(mpp.find(nums[i]+k)!=mpp.end()){
                ans+=mpp[nums[i]+k];
            }
            mpp[nums[i]]++;
        }
        return ans;
    }
};