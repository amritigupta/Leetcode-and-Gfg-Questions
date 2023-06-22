//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
	int minDifference(int arr[], int n)  { 

	    int sum=0;
	    for(int i=0; i<n; i++){
	        sum+=arr[i];
	    }
	    
	    int k = sum;
	    vector<vector<bool>>  dp(n, vector<bool> (k+1, 0));
	    
	    //base case (target = 0 returrns true)
	    for(int i=0; i<n ; i++){
	        dp[i][0]= true;
	    }
	    
	    //base case (if ind = 0 && target = arr[0])
	    if(arr[0] <= k) dp[0][arr[0]]=true;
	    
	    
	    // 0 ind is also marked
	    for(int ind = 1; ind <n ; ind++){
	        // 0 target is marked
	        for(int target = 1; target <=k ; target++){
	            bool nottake = dp[ind-1][target];
	            bool take =false;
	            if(arr[ind] <= target) take = dp[ind-1][target - arr[ind]];
	            
	            dp[ind][target] = nottake|take;
	        }
	    }
	    
	    
	    int mini = 1e9;
	    for(int s1=0; s1<=sum; s1++){
	        if(dp[n-1][s1] == true){
	            mini = min(mini, abs( (sum-s1) - s1));
	        }
	    }
	    
	    return mini;
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends