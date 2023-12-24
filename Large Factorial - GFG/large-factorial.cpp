//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{
public:
    long long int m=1000000007;
  
   vector<long long> factorial(vector<long long> a, int n) {
       unordered_map<long long,long long>mp;
       long long maxi=0;
       for(int i=0;i<n;i++){
          maxi=max(maxi,a[i]);
       }
       long long curr=1;
       mp[0]=1;
       for(int i=1;i<=maxi;i++){
           curr=(curr*i)%m;
           mp[i]=curr;
       }
       vector<long long>ans;
       for(int i=0;i<n;i++){
          ans.push_back(mp[a[i]]); 
       }
       return ans;
   }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends