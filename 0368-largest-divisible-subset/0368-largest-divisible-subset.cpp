class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
 
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for(int i=0; i<n ; i++){
            hash[i]=i;
        }
        
        int maxi=1;
        int mxindex=0;
        for(int i=1; i<n ; i++){
            for(int prev = 0; prev<i; prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                mxindex= i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[mxindex]);
        while(mxindex!=hash[mxindex]){
            mxindex = hash[mxindex];
            ans.push_back(nums[mxindex]);
        }
        
        return ans;
    }
};