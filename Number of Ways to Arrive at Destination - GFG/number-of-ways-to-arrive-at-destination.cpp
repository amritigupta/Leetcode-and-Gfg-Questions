//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
//create an adjacent vector containing pair(node,time)
        vector<pair<int,int>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

//create a distant vector and a ways vector for tracing number of ways having similar wait to reach a node       

        vector<long> dist(n,1e12),ways(n,0);

//define a priority_queue
        priority_queue<pair<long,long>,vector<pair<long,long>>,
        greater<pair<long,long>>>pq;
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        int mod = (int)(1e9 + 7);
        while(!pq.empty()){
            long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjNode = it.first;
                long tm = it.second;
                
                if(dis + tm < dist[adjNode]){
                    dist[adjNode] = dis + tm;
                    pq.push({dis + tm,adjNode});
                    ways[adjNode] += (ways[node] % mod);
                    
                }else if(dis + tm == dist[adjNode]){
                    ways[adjNode] += ( ways[node]%mod);
                }
            }
        }
        return ways[n-1]%mod;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends