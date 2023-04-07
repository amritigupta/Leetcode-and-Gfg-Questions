//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>adjls[V];
		for(int i=0; i<V; i++){
			for(int j=0; j<V; j++){
				if(adj[i][j]==1 && i!=j){
					adjls[i].push_back(j);
					adjls[j].push_back(i);
				}
			}
		}
       
       
		vector<int>v(V, 0); //visited array
       
		int cnt=0;
		for(int i=0; i<V; i++){
			if(v[i]==0){
				cnt++;
				queue<int>q;
				q.push(i);
				while(!q.empty()){
					int ft=q.front();
					q.pop();
					for(auto it: adjls[ft]){
						if(!v[it]){
							v[it]=1;
							q.push(it);
						}
					}
				}
			}
		}
		return cnt;
	}
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends