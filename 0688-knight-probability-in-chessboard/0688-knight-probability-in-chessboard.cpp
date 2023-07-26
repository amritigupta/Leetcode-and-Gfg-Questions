class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> memo(N+1, vector<vector<double>>(N+1, vector<double>(K+1, -1)));
        return helper(N, K, r, c, memo);
    }
    
    double helper(int N, int K, int row, int col, vector<vector<vector<double>>>& memo){

        if(row < 0 || col < 0 || row >= N || col >= N) return 0.0;
        
        if(K == 0) return 1.0;
        
        if(memo[row][col][K] != -1) return memo[row][col][K];
        
        double ans = 
            helper(N, K-1, row+2, col+1, memo) + helper(N, K-1, row+1, col+2, memo) +       
            helper(N, K-1, row-1, col+2, memo) + helper(N, K-1, row-2, col+1, memo) + 
            helper(N, K-1, row-2, col-1, memo) + helper(N, K-1, row-1, col-2, memo) +
            helper(N, K-1, row+1, col-2, memo) + helper(N, K-1, row+2, col-1, memo);
        
        double result  = ans / 8.0;
        memo[row][col][K] = result;
        return result;
    }
};