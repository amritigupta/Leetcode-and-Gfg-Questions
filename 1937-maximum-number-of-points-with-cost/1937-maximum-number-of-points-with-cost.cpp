class Solution {
    // MEMOIZATION

    // long long f(int row, int col, vector<vector<int>>& points, int n, int m, vector<vector<long long>> &dp){
    //     if(row==n){
    //         return 0;
    //     }

    //     if(dp[row][col]!=-1) return dp[row][col];

    //     long long pts = points[row][col];

    //     long long ans = pts;
    //     for(int i=0; i<m; i++){
    //         ans = max(ans,pts+f(row+1, i, points, n, m, dp) - abs(i-col));
    //     }

    //     return dp[row][col]=ans;
    // }
public:
    // long long maxPoints(vector<vector<int>>& points) {
    // //     long long ans = 0;
    // //     int n = points.size();
    // //     int m = points[0].size();

    // //     vector<vector<long long>> dp(n, vector<long long>(m, -1));

    // //     for(int i=0; i<m; i++){
    // //         ans=max(ans, f(0, i, points, n, m, dp));
    // //     }

    // //     return ans;
    // // }


    // // TABULATION 

    // long long maxPoints(vector<vector<int>>& points) {
    //     long long ans = 0;
    //     int n = points.size();
    //     int m = points[0].size();

    //     vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));

    //     for(int i=n-1; i>=0; i--){ //row
    //         for(int j=m-1; j>=0; j--){ //col
    //             long long pts = points[i][j];
    //             long long temp = pts;
    //             for(int k=0; k<m; k++){ // i
    //                 temp = max(temp, pts+dp[i+1][k] - abs(k-j));
    //             }
    //             dp[i][j]=temp;
    //         }
    //     }

    //     for(int i=0; i<m; i++){
    //         ans=max(ans, dp[0][i]);
    //     }

    //     return ans;
    // }


    // optimized tabulation to remove TLE

    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();

        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        vector<long long> leftmax(m+1, 0);
        vector<long long> rightmax(m+1, 0);
        for(int row=n-1; row>=0; row--){
            leftmax[0]=dp[row+1][0];
            for(int col=1; col<m; col++){
                leftmax[col]= max(dp[row+1][col], leftmax[col-1]-1);
            }

            rightmax[m-1]=dp[row+1][m-1];
            for(int col=m-2; col>=0; col--){
                rightmax[col]=max(dp[row+1][col], rightmax[col+1]-1);
            }

            for(int col=0; col<m; col++){
                dp[row][col]= max(leftmax[col], rightmax[col])+points[row][col];
            }
        }

        long long ans = 0;
        for(int i=0; i<m ; i++){
            ans=max(ans , dp[0][i]);
        }
        return ans;

    }
};