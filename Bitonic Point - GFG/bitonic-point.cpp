//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) 
	{
	    // O(logN)
	    int l = 0, h = n-1;
	    while(l<=h)
	    {
	        int mid = (l+h)/2;
	        if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1]))
	            return arr[mid];
	        else if(mid < n-1 && arr[mid] < arr[mid+1])
	            l = mid + 1;
	        else 
	            h = mid - 1;
	    }
	    return -1;
	}
	
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends