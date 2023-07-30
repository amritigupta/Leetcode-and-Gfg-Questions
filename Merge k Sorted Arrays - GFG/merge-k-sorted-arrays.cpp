//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
 /*
    METHOD-1 (USING SORTING) 
    TC-> O(N*K*Log(N*K)
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int>v;
        for(int i=0;i<K;i++){
            for(int j=0;j<K;j++)
            {
                v.push_back(arr[i][j]);
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
    
    */
    
    /*
    METHOD-2 (EFFICIENT SOLUTION)
     TC-> O(N*K*LogK)
    */
    
    typedef pair<int,pair<int,int>>triplet;
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<triplet,vector<triplet>,greater<triplet>>pq;
        
        for(int i=0;i<K;i++){
            pq.push({arr[i][0],{i,0}});
        }
        
        vector<int> res;
        
        while(!pq.empty()){
            triplet curr=pq.top();
            pq.pop();
            
            res.push_back(curr.first);
            
            int ap=curr.second.first;
            int vp=curr.second.second;
            
            if(vp+1<K){
                pq.push({arr[ap][vp+1],{ap,vp+1}});
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends