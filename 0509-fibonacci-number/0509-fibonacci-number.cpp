class Solution {
//     int f(int N, vector<int> &dp){
//         if(N < 2)
//             return N;
          
//         if(dp[N]!=-1){
//             return dp[N];
//         }
        
//         return dp[N] = f(N-1, dp) + f(N-2, dp);
//     }
public:
    int fib(int N) {
        vector<int> dp(N + 1, -1);
        // return f(N, dp);
        if(N < 2){
            return N;
        }
        
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2; i<=N ; i++){
            dp[i]= dp[i-1]+dp[i-2];
        }
        
        return dp[N];
    }
};