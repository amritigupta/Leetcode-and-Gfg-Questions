class Solution {
public:
    
  int prime = 1e9+7;
    
  int f(string s1, string s2, int ind1, int ind2,vector<vector<int>>& dp){
      if(ind2<0){
          return 1;
      }
      if(ind1<0){
          return 0;
      }
      if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];      
      
      if (s1[ind1]==s2[ind2]){
          int ans1 = f(s1, s2, ind1-1, ind2, dp); //dont match
          int ans2 = f(s1, s2, ind1-1, ind2-1, dp); //match
          
          return dp[ind1][ind2] = (ans1)%prime+ans2%prime;
      }
      else{
          return dp[ind1][ind2] = f(s1, s2, ind1-1, ind2, dp);
      }
  }

  int numDistinct(string &t, string &s) {
    int lt = t.length();
    int ls = s.length();
    
    vector<vector<int>> dp(lt,vector<int>(ls,-1));
    return f(t,s,lt-1,ls-1,dp);
  } 
    
};