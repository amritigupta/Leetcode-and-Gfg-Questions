//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    static bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.first< b.first){
            return true;
        }
        if(a.first==b.first){
            return a.second>b.second;
        }
        return false;
    }
    
    public:

    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>> vec;
    	for(int i=0; i<n; i++){
    	    vec.push_back({arr[i],dep[i]});
    	}
    	
    	sort(vec.begin(), vec.end(), cmp);
    	
    	int cnt = 1;
    	unordered_map<int, int> mpp;
    	mpp[cnt] = vec[0].second;
    	
    	for(int i=1; i<n; i++){
    	    bool flag=0;
    	    for(auto it : mpp){
    	        if (vec[i].first > it.second ){
    	            flag=1;
    	           // cout<<it.second<<" ";
    	            mpp[it.first] = vec[i].second;
    	           // cout<<it.second<<endl;
    	            break;
    	        }
    	    }
    	    if (flag){
    	        continue;
    	    }
    	    
    	    cnt++;
    	    mpp[cnt]= vec[i].second;
    	}
    	
    	return cnt;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends