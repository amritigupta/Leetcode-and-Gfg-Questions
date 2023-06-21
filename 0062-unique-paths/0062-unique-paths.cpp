class Solution {
    int f (int i, int j , vector<vector<int>> & dp){
        if(i<0 || j<0){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
 
        int f1 = f(i, j-1, dp);
          int f2 = f(i-1,j,dp);

        
        return dp[i][j]= f1+f2;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return f(m-1, n-1 , dp);
    }
};