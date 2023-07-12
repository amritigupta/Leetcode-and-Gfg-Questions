//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = 1e9+7;
    int f(int ind, int arr[], int sum, vector<vector<int>> &dp){

        if(ind==0){
            if(arr[0]==0 && sum==0){
                return 2;
            }
            else if(sum==0){
                return 1;
            }
            else if(arr[0]==sum){
                return 1;
            }
            else{
                return 0;
            }
        }
        
    
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        
        int notpick = f(ind-1, arr, sum, dp);
        int pick = 0;
        if(arr[ind]<=sum){
            pick = f(ind-1, arr, sum-arr[ind], dp);
        }
        
        return dp[ind][sum] = (pick+notpick)%mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
         return f(n-1, arr, sum, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends