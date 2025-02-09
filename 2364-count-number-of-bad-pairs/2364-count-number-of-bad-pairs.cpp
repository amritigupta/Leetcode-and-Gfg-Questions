class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        long long ans=0;
        for(int i=0; i<n; i++){
            mpp[nums[i]-i]++;
            if((i+1)-mpp[nums[i]-i]<=0){
                continue; //dont add anything
            }
            else{
                ans+=(i+1-(mpp[nums[i]-i]));
            }
        }
        return ans;
    }
};