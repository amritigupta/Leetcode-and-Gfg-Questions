//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
int f(int wt[], int val[], int ind, int W, vector<vector<int>>& dp){

    if(ind == 0){
        if(wt[0] <=W) return val[0]; //take that element
        else return 0; //cant take element at 0
    }
    
    if(dp[ind][W]!=-1)
        return dp[ind][W];
        
    int notTaken = 0 + f(wt,val,ind-1,W,dp); //dont take the element at ith
    
    int taken = INT_MIN;
    
    if(wt[ind] <= W) //take the element at ith
        taken = val[ind] + f(wt,val,ind-1,W-wt[ind],dp);
        
    return dp[ind][W] = max(notTaken,taken); //find max profit
 }

public:

    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
            vector<vector<int>> dp(n,vector<int>(W+1,-1));
            return f(wt, val, n-1, W, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends