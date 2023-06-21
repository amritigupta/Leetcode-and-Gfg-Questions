//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    
    int f(int ind, vector<int> &dp , int *a){
        if(ind < 0 ){
            return 0;
        }
        if(ind==0){
            return a[ind];
        }
        
        
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        int pick = a[ind] + f(ind-2, dp, a);
        int notpick = 0 + f(ind-1, dp, a);
        
        return dp[ind] = max(pick, notpick);
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n+1, -1);
	    
	    return f(n-1, dp, arr);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends