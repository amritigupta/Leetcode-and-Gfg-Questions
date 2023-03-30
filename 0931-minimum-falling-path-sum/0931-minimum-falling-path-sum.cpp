class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n  = a.size();
        int dp[n][n];
        for (int j=0; j<n ; j++){
            dp[0][j]= a[0][j];
        }
        
        for (int i=1; i<n; i++){
            for (int j=0; j<n; j++){
                int u = a[i][j]+ dp[i-1][j];
                int ld = a[i][j];
                if (j-1>=0) ld+=dp[i-1][j-1];
                if (j-1<0) ld+=1e5;
                int rd = a[i][j];
                if (j+1<=n-1) rd+=dp[i-1][j+1];
                if (j+1>=n) rd+= 1e5;
                
                dp[i][j]=min(u,min(ld,rd));
            }
        }
                    
        int mini = dp[n-1][0] ;
        for (int k=1; k<n; k++){
            mini = min(mini, dp[n-1][k]);
        }
        
        return mini;
    }
};