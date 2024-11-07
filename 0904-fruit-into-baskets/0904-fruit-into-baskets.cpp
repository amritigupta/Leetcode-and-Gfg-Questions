class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int i=0, j=0;
        unordered_map<int,int> mpp;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp.size()>2){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
            }
            int sum=0;
            for(auto it: mpp){
                sum+=it.second;
                // cout<<it.first<<' '<<it.second<<endl;
            }
            maxi=max(maxi, sum);
            j++;
        }
        return maxi;
    }
};