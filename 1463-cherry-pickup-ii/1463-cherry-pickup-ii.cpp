class Solution {
    int f(int i, int j1, int j2, int m , int n , vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(j1<0 || j2<0 || j1>=n || j2>=n){
            return 0;
        }
        if(i==m-1){
            if(j1==j2) return  grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        
        if(dp[i][j1][j2] !=-1){
            return dp[i][j1][j2];
        }
        
        int maxi=INT_MIN;
        for(int dj1=-1; dj1<=1; dj1++){
            for(int dj2=-1; dj2<=1; dj2++){
                if(j1==j2){
                    maxi = max(maxi, grid[i][j1]+ f(i+1, j1+dj1, j2+dj2, m,n,grid,dp));
                }
                else{
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(i+1, j1+dj1, j2+dj2, m,n,grid,dp));
                }
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int> (n+1,-1))); 
        return f(0, 0, n-1, m, n, grid, dp);
    }
};
