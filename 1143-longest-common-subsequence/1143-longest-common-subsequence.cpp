class Solution {
    int f(int i1, int i2, string &s , string &t, vector<vector<int>> &dp){
        if(i1<0 || i2<0){
            return 0;
        }
        
        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }
        
        if(s[i1]==t[i2]){
            return dp[i1][i2] = 1+f(i1-1, i2-1,s,t,dp);
        }
        else{
            return dp[i1][i2] = max(f(i1-1,i2,s,t,dp) , f(i1,i2-1,s,t,dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return f(n-1, m-1, text1, text2, dp);
    }
};