class Solution {
    

public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), dp2(n, 1);
        int ans = 0;
        for (int ind=1; ind<n; ind++) {
            if (arr[ind] > arr[ind-1]) {
                dp[ind] = 1 + dp[ind-1];
            }
        }
        for (int ind=n-2; ind>=0; ind--) {
            if (arr[ind] > arr[ind+1]) {
                dp2[ind] = 1 + dp2[ind+1];
            }
        }
        for (int i=0; i<n; i++) {
            if (dp[i] > 1 && dp2[i] > 1) {
                ans = max(dp[i] + dp2[i] - 1, ans);
            }
        }
        return ans;
    }
};