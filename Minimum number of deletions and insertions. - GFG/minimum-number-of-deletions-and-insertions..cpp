//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	int lcs (string s , string t ){
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for (int i=0; i<=n ; i++){
            dp[i][0]=0;
        }
        for (int j=0; j<=m;j++){
            dp[0][j]=0;
        }
        
        for (int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }	

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int lcslen = lcs(str1, str2);
	    int n = str1.size();
	    int m = str2.size();
	    
	    return (n-lcslen)+(m-lcslen);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends