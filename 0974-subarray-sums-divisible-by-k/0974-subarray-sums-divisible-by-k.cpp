class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        nums[0]=nums[0];
        for(int i=1; i<n; i++){
            nums[i]+=nums[i-1];
        }
        nums[0]%=k;
        for(int i=1; i<n; i++){
            nums[i]=nums[i]%k;
            // cout<<nums[i]<<endl;
        }
        
        // -1 2 9
        // -1 1 10
        // -1 1 0
        
        int ans=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                ans++;
            }
            if(nums[i]<0){
                nums[i]=k+nums[i];
            }
            if(mpp.find(nums[i])!=mpp.end()){
                ans+=mpp[nums[i]];
            }
            mpp[nums[i]]++;
        }
        
        return ans;
    }
};