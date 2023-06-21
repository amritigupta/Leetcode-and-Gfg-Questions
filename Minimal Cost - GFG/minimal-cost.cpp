//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int f(int i , int k, vector<int>& height, vector<int>& dp){
        if(i<=0){
            return 0;
        }
        
        int mmsteps = INT_MAX;
        if (dp[i]!=-1){
            return dp[i];
        }
        for(int j=1; j<=k ; j++){
            if(i-j >= 0){
             int jump = abs(height[i]- height[i-j]) + f(i-j, k, height, dp);
             mmsteps = min(jump, mmsteps);
            }
        }
        
        return dp[i]=mmsteps;
        
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n+1, -1);
        
        return f(n-1 , k, height, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends