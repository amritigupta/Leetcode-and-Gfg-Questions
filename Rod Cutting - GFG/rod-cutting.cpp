//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    int f (int ind, int price[], int n,  vector<vector<int>> &dp){
        
        if(ind==0){
            if(n%(ind+1)==0){
                return (n/(ind+1))*price[0];
            }
            else{
                return 0;
            }
        }
        
        if(dp[ind][n]!=-1) return dp[ind][n];
        
        int nottake = f(ind-1, price, n, dp);
        int take = INT_MIN;
        if(ind+1<=n){
            take = price[ind]+f(ind, price, n-(ind+1), dp);
        }
        
        return dp[ind][n] = max(take,nottake);
    }
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(n-1, price, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends