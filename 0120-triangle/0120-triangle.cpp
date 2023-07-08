class Solution {
    int f(int i, int j, int m, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp ){
        if(i==m-1){ //on last row
            return triangle[i][j];
        }
        if(i>=m || j>i+1){
            return 1e5;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        

           int one = triangle[i][j] + f(i+1, j, m, n, triangle, dp);
            int two = triangle[i][j] + f(i+1, j+1, m , n , triangle, dp);

        
        return dp[i][j] = min(one, two);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size(); //last row size
         vector<vector<int>>dp (m+1, vector<int> (n+1,-1));
        
        return f(0,0,m,n,triangle, dp);     
    }
};