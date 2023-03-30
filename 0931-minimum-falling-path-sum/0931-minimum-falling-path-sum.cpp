class Solution {
    int f (int i, int j, vector<vector<int>>& a,  vector<vector<int>> &dp){
        int n = a.size();
        if (j<0 || j>=n){
            return 1e5;
        }
        if (i==0){ //base case
            return a[i][j];
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        
        int u = a[i][j]+f(i-1, j, a, dp);
        int ld = a[i][j]+f(i-1,j-1,a,dp);
        int rd = a[i][j]+ f(i-1, j+1, a,dp);
        
        return dp[i][j]=min(u,min(ld,rd));
    }
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int mini = INT_MAX;
        for (int i=0; i<n; i++){
            mini = min(mini, f(n-1,i,a,dp));
        }
        
        return mini;
       /* int n  = a.size();
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
        
        return mini; */
    }
};