//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        
        int n = q.size()/2;
        stack<int> s;
        vector<int> ans;
        
        //push half element to stack
        for (int i=0; i<n; i++){
            s.push(q.front());
            q.pop();
        }
        
        //pop half element to queue
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
        
        //move front half element to end half element in queue
        for (int i=0; i<n; i++){
            q.push(q.front());
            q.pop();
        }
        
        //push half element to stack
        for (int i=0; i<n; i++) {
            s.push(q.front());
            q.pop();
        }
        
        //again push to queue in interleave
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
            q.push(q.front());
            q.pop();
        }
        
        //push queue in ans
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends