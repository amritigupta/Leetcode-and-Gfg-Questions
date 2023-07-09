//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
int countsmallerthanequalto(vector<int> &row, int num){
    int l=0;
    int r = row.size()-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(row[mid]>num){
            r = mid-1;
        }
        else{
            l=mid+1;
        }
    }
    
    return l;
}

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int l = 1;
        int r = 1e9;
        while(l<=r){
            int mid = l+(r-l)/2;
            int cnt =0;
            for(int i=0; i<R ; i++){
                cnt+=countsmallerthanequalto(matrix[i], mid);
            }
            
            if(cnt<=(R*C)/2) l=mid+1;
            else r=mid-1;
        }
        
        return l;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends