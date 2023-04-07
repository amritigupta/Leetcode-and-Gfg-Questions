class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // subset means no order
        // subsequence means in order
  
        int n = nums.size();
        vector<int> dp(n, 1), hash(n, 0);
        int ans = INT_MIN;
        int lastIndex = 0;
        vector<int> res;
        
        
        sort(begin(nums), end(nums));
        
        
        for (int ind=0; ind<n; ind++) {
            for (int prev=0; prev<ind; prev++) {
                if (nums[ind] % nums[prev] == 0 && 1 + dp[prev] > dp[ind]) {
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                }
            }
            
            if (dp[ind] > ans) {
                ans = dp[ind];
                lastIndex = ind;
            }
            
        }
        
        res.emplace_back(nums[lastIndex]);
        
        
        for (int i=0; i<ans-1; i++) {
            res.emplace_back(nums[hash[lastIndex]]);
            lastIndex = hash[lastIndex];
        }
        return res;
    }

    
};