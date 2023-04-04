class Solution {
    
    int lcs(string s, string t){
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for (int i=0; i<=n; i++){dp[i][0]=0;}
        for (int j=0; j<=m; j++){dp[0][j]=0;}
        
        for (int i=1; i<=n; i++){
            for(int j=1; j<=m ; j++){
                if (s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        // int lenlcs= dp[n][m];
        
//         string ans="";
//         int index=lenlcs-1;
//         for (int i=0; i<lenlcs; i++){
//             ans+='$'
//         }
//         int i =n;
//         int j=m;
        
//         while (i>0 && j>0){
//             if (s[i-1]==t[j-1]){
//                 ans[index]=s[i-1];
//                 i--;
//                 j--;
//                 index--;
//             }
//             else if (dp[i-1][j]>dp[i][j-1]){
//                 i--;
//             }
//             else if(dp[i][j-1]> dp[i-1][j]){
//                 j--;
//             }
//         }
//         return ans;
    }
public:
    int longestPalindromeSubseq(string s) {
        string t = s; 
        reverse(t.begin(), t.end());
        
        return lcs(s,t);
    }
};