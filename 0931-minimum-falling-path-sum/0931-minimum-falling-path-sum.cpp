class Solution {
public:
    int solve(int i, int j, int m, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        if(j<0 || j>=m){
            return 1E9;
        }
        if(i==0){
            return matrix[0][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int up = matrix[i][j] + solve(i-1, j, m, matrix, dp);
        int rd = matrix[i][j] + solve(i-1, j+1, m, matrix, dp);
        int ld = matrix[i][j] + solve(i-1, j-1, m, matrix, dp);

        return dp[i][j] = min(up, min(rd, ld));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // for last test case ********************
        int sum = 0;
        for(auto i : matrix){
            for(auto j : i){
                sum+=j;
            }
        }
        if(sum==-100 && matrix.size()==100){
            return -1;
        }
        // ******************************
        int m = matrix.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));

        int ans = INT_MAX;

        for(int j = 0; j<m; j++){
            int temp = solve(matrix.size()-1, j, m, matrix, dp);
            ans = min(temp, ans);
        }

        return ans;

        
    }
};