class Solution {
    long long f(int row, int col, vector<vector<int>>& points, int n, int m, vector<vector<long long>> &dp){

        if(dp[row][col]!=-1) return dp[row][col];

        long long pts = points[row][col];

        long long ans = pts;
        for(int i=0; i<m; i++){
           if(row+1<n) ans = max(ans,pts+f(row+1, i, points, n, m, dp) - abs(i-col));
        }

        return dp[row][col]=ans;
    }
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long ans = 0;
        int n = points.size();
        int m = points[0].size();

        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        for(int i=0; i<m; i++){
            ans=max(ans, f(0, i, points, n, m, dp));
        }

        return ans;
    }
};