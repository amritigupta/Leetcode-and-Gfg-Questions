//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isvalid(int mid, int M , int A[], int N){
        int student=1;
        int bookcount=A[0];
        
        for(int i=1; i<N; i++){
            if(bookcount+A[i] <= mid){
                bookcount+=A[i];
            }
            else{
                student++;
                bookcount=A[i];
            }
            if(student>M){
                return false;
            }
        }
        
        return true;
    }
   
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N){
            return -1;
        }
        int s = *max_element(A,A+N);
        int e=0;
        for(int i=0; i<N ; i++){
            e+=A[i];
        }
        
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isvalid(mid, M, A, N)){
                ans = mid;
                e = mid-1;
            }
            else{
                s=mid+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends