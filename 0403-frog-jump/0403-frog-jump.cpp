class Solution {
    bool help(int ind, int jump, vector<int>&stones, vector<vector<int>> &dp){
        if( ind == stones.size()-1 ){
            return true;
        }
        
        if(dp[ind][jump]!=-1){
            return dp[ind][jump];
        }
        
        bool ans = false;
        for(int i=-1 ; i<=1; i++){
            
            if(jump==1 && i==-1){
                continue;
            }
            
            bool ans1 = false;
            int f = stones[ind] + jump + i;
            auto it = find(stones.begin(), stones.end(), f);
                
            if(it != stones.end()){
               ans1 = help(it-stones.begin(), jump+i, stones, dp);
            }
            
            else{
                ans1 = false;
            }
            
            ans = ans||ans1;
        }
        
        return dp[ind][jump]=ans;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1]!=1){
            return false;
        }
        vector<vector<int>> dp(n+1, vector<int>(n+3,-1));
        return help(1, 1, stones, dp);
    }
};