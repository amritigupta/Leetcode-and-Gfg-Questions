class Solution {
    int f (int i, int j, string s, string t, vector<vector<int>> &dp){
        // base cases
        
        if(i<0 && j<0){ // if "" & ""
            return 0;
        }
        if(j<0){ //j is exhausted "abcd" && ""
                 // u require (i+1) operations then
            return i+1;
        }
        if(i<0){ //i is exhausted "" && "hor"
                 //to convert we can make 3 insertions or 3 deletions
            return j+1;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]){
            return dp[i][j] = f(i-1, j-1, s,t, dp);
        }
        else{
            int insert = 1 + f(i, j-1, s, t, dp);
            int del =  1 + f(i-1, j, s , t, dp);
            int replace = 1 + f(i-1,j-1,s,t,dp);
            
            return dp[i][j] = min(insert, min(del, replace));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return f(n-1, m-1, word1, word2, dp);
    }
};