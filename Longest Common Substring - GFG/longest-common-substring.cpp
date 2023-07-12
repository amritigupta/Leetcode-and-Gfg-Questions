//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution{
    public:
    int t[1001][1001]; //declaring our cache
    int maxi = 0; //taking a maxi variable for finding the longest size

    int helper(string &S1, string &S2, int n, int m){
        //if anyoun of them is empty then return 0, con substring can form with empty string
        if(n == 0 || m == 0) return 0;
        
        //if subproblem is already calculated then return it
        if(t[n][m] != -1) return t[n][m];
        
        if(S1[n-1] == S2[m-1]){
            // if its common then we can take current element
            t[n][m] = 1 + helper(S1, S2, n-1, m-1);
            
            //update out max size of LCS
            maxi = max(maxi, t[n][m]);
        }
        else{
            //if not matching then update the size of the string 0
            t[n][m] = 0;
 
        }
        helper(S1, S2, n-1, m); //traverse futher string
        helper(S1, S2, n, m-1); //traverse futher string
                     
     
        return t[n][m];
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        memset(t, -1, sizeof(t));
        helper(S1, S2, n, m);
        return maxi; // This will be our answer
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends