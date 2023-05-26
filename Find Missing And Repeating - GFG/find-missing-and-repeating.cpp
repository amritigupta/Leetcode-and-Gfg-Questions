//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int mpp[n+1]={0};
        for(int i=0; i<n ; i++){
            mpp[arr[i]]++;
        }
        int repeating = -1;
        int missing = -1;
        
        for(int i=1; i<=n ; i++){
            if(mpp[i]==2){
                repeating = i;
            }
            else if(mpp[i]==0){
                missing = i;
            }
            
            else if(repeating !=-1 && missing !=-1){break;}
        } 
        vector<int> v = {repeating, missing};
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends