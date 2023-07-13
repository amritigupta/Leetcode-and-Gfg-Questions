class Solution {
    bool f(int i, int j, string &s, string & t, vector<vector<int>> &dp){
        if(i<0 & j<0){
            return true;
        }
        
        if(j<0) 
            return false;
        
        if(i<0){
            for(int k=0; k<=j ; k++){
                if(t[k]!='*'){
                    return false;
                }
            }           
            return true;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==t[j]){
            return dp[i][j] =  f(i-1,j-1,s,t,dp);
        }
        else if(t[j]=='?'){
            return  dp[i][j] = f(i-1,j-1,s,t,dp);
        }
        else if(t[j]=='*'){
            // * represents nothing
            // * represents 1 or more
            return dp[i][j] = f(i, j-1, s,t , dp)||f(i-1,j,s,t,dp);
        }
        
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(n-1, m-1, s, p, dp);
    }
};