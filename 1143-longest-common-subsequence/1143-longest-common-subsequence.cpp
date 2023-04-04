class Solution {
//     int f (int i, int j, string s1, string s2, vector<vector<int>> &dp){
//         if (i<0 || j<0){
//             return 0;
//         }
//         if (s1[i]==s2[j]){
//             return 1+f(i-1,j-1,s1,s2,dp);
//         }
        
//         if (dp[i][j]!=-1){
//             return dp[i][j];
//         }

//         return dp[i][j]= max(f(i-1, j, s1,s2,dp),f(i,j-1,s1,s2,dp));
//     }
public:
//     // MEMOIZATION
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();
        
//         vector<vector<int>>dp(n, vector<int>(m,-1));
//         return f(n-1, m-1, text1, text2,dp);
//     }
    
    //TABULATION
    
    int longestCommonSubsequence(string s, string t){
        // USE INDEX SHIFTING 
        
        // if i = 0, it points to index -1 in array, if i = 1 , points to index 0 in array, if i=n points to n-1 in array
        
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1,0)); 
        
        for (int i=0; i<n; i++){
            dp[i][0]  = 0;      
        }
        
        for (int j=0; j<m; j++){
            dp[0][j] = 0;
        }
        
        for (int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (s[i-1]==t[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};