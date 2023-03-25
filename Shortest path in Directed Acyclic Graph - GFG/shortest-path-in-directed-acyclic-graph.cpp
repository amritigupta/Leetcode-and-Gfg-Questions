//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
    // void topoSort (int node, vector<pair<int,int>> adj[], int vis[], stack<int> &s){
    //     vis[node]=1;
    //     for (auto it: adj[node]){
    //         int v = it.first;
    //         if (!vis[v]){
    //             topoSort(v, adj, vis, s);
    //         }
    //     }
        
    //     s.push(node);
    // }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for (int i=0; i<M ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
    //     int vis[N]={0};
    //     stack<int> s;
    //     for (int i=0; i<N; i++){
    //         if (!vis[i]){
    //             topoSort(i, adj, vis, s);
    //         }
    //     }
        
    //     vector<int> dist(N);
    //     for (int i=0; i<N; i++) dist[i] = 1e9; 
        
    //     dist[0]=0;
        
    //     while (!s.empty()){
    //         int node = s.top();
    //         s.pop();
            
    //         for (auto it: adj[node]){
    //         int v = it.first;
    //         int wt = it.second;
            
    //         if (dist[node]+wt < dist[v]){
    //             dist[v]= dist[node]+wt;
    //           }
    //         }
    //     }
        
        
    //   for (int i = 0; i < N; i++) {
    //     if (dist[i] == 1e9) dist[i] = -1;
    //   }
    //     return dist;
    // }
    
    vector<int>indegree(N,0);

  for(int i=0; i<N; i++){

      for(auto it: adj[i]){

          indegree[it.first]++;

      }

  }

 

queue<int>q;

for(int i=0; i<N; i++){

    if(indegree[i] == 0)

    q.push(i);

}

 vector<int>dis(N, INT_MAX);

 dis[0] = 0;

 

 while(!q.empty()){

     int node = q.front() ;
     q.pop();

    //  int wt = q.front().second;

             for(auto it: adj[node]){

                 int v = it.first;

                 int wt = it.second;

                 if(dis[node] != INT_MAX){

                   if(dis[node] + wt < dis[v]){

                     dis[v] = dis[node] + wt;

                     q.push(v);
 
                    }

                  }

             }

         }

        

        for(int i=0; i<N; i++){

            if(dis[i] == INT_MAX)

            dis[i] = -1;

        }

        return dis;

 

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends