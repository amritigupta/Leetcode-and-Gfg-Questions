//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        //code here
        if(n==1){
            vector<long long> v;
            v.push_back(1);
            return v;
        }
        long long last=1;
        long long slast=1;
        vector<long long> v;
        v.push_back(slast);
        v.push_back(last);
        
        for(int i=3; i<=n; i++){
            long long temp = slast+last;
            v.push_back(temp);
            slast = last;
            last=temp;
        }
        
        return v;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends