class Solution {
    int f(int row, int idx, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
        if(row==n-1){
            return triangle[row][idx];
        }

        if(dp[row][idx]!=-1) return dp[row][idx];

        int mini = INT_MAX;
        mini = min(mini, min(f(row+1, idx, triangle, n, dp), f(row+1, idx+1, triangle,n, dp)));

        return dp[row][idx]= triangle[row][idx] + mini;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(201, -1));
        return f(0,0, triangle, n, dp);
    }
};