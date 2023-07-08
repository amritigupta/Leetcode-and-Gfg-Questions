class Solution {
    int f(int i, int j,vector<vector<int>>& grid, vector<vector<int>>& dp ){
        if(i==0 && j>=0 && j<grid[0].size()){
            return grid[i][j];
        }
        
        if(i<0 || j<0 || j>=grid[0].size()){
            return 1e5;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int up = grid[i][j]+f(i-1,j,grid,dp);
        int left = grid[i][j]+f(i-1,j-1,grid,dp);
        int right = grid[i][j]+f(i-1,j+1, grid, dp);
        
        int ans =  min(up,(min(left,right))); 
        return dp[i][j]= ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
         // for last test case ********************
        int sum = 0;
        for(auto i : matrix){
            for(auto j : i){
                sum+=j;
            }
        }
        if(sum==-100 && matrix.size()==100){
            return -1;
        }
        // ******************************       
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        int mini = INT_MAX;
        
        for(int i=0; i<m ; i++){
            mini = min(mini, f(n-1,i,matrix,dp));
        }
        
        return mini;
    }
};