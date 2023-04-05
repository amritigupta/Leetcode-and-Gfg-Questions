class Solution {

public:
///// MEMOIZATION
    int f(int ind,int buy, int cap ,int n ,vector<int>&v,vector<vector<vector<int>>> &dp){
    int notpick,pick;
    if(ind==n) return 0;
    if(cap == 0) return 0;
    if(dp[ind][buy][cap] != -1 ) return dp[ind][buy][cap];
    if(buy){
        notpick = 0 + f(ind+1,1,cap,n,v,dp);
        pick = v[ind] + f(ind+1,0,cap-1,n,v,dp);
    }
    else{
        notpick = 0 + f(ind+1,0,cap,n,v,dp);
        pick = -v[ind] + f(ind+1,1,cap,n,v,dp);
    }
    return dp[ind][buy][cap] = max(pick,notpick);
}

int maxProfit(vector<int>&v){
    int n = v.size();
    vector<vector<vector<int>>> dp (n,vector<vector<int>>(2,vector<int>(3,-1)));
    return f(0,0,2,n,v,dp);
}
};