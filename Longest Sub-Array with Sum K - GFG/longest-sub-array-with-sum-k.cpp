//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
  
    int lenOfLongSubarr(int a[],  int n, int k) {
 
        int ans=0;        
        int sum=0;
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        for(int i=0; i<n; i++){
            sum+=a[i];
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
            if(mpp.find(sum-k)!=mpp.end()){
                ans=max(ans,i-mpp[sum-k]);
            }
        }
        return ans;
    
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends