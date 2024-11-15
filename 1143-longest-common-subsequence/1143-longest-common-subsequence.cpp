class Solution {
    int f(int i, int j, int n, int m, string &text1, string &text2, vector<vector<int>> &dp){
        if(i>=n || j>=m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(text1[i]==text2[j])  return dp[i][j] = 1+f(i+1, j+1, n, m, text1, text2, dp);
        int f1 = f(i+1, j, n,m , text1, text2, dp);
        int f2 = f(i, j+1, n, m, text1, text2, dp);
        return dp[i][j] = max(f1, f2);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
        // return f(0,0,text1.size(),text2.size(), text1, text2, dp);

        // tabulation
        int m = text2.size();
        int n = text1.size();
        for(int i=0; i<=m; i++){
            dp[n][i]=0;
        }
        for(int i=0; i<=n; i++){
            dp[i][m]=0;
        }

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(text1[i]==text2[j]) dp[i][j]= 1+dp[i+1][j+1];
                else{
                    dp[i][j]= max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
    }
};