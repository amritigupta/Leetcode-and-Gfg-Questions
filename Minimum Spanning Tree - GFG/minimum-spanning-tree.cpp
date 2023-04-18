//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class DisjointSet{
    vector <int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0 );
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node){
        if (node == parent[node]){
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if(ulp_u==ulp_v){
            return;
        }

        if(rank[ulp_u]< rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }

        else if (rank[ulp_v]< rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }

        else { //if same rank 
            parent[ulp_v] = ulp_u; // v attached to u
            rank[ulp_u]++; //larger one grows in size
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if(ulp_u==ulp_v){
            return;
        }     

        if(size[ulp_u]< size[ulp_v])  {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};


class Solution

{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    // int spanningTree(int V, vector<vector<int>> adj[])
    // {
    //     // code here
        
    //     //PRIMS ALGO
        
    //     // MIN HEAP {WT,NODE}
    //     // VISITED ARRAY
        
    //     vector<int> vis(V, 0);
    //     priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
    //     int sum=0; 
    //     pq.push({0,0});
    //     while(!pq.empty()){
    //         auto it = pq.top();
    //         pq.pop();
    //         int node = it.second;
    //         int wt = it.first;
            
    //         if (vis[node]){
    //             continue;
    //         }
    //         else{
    //             //add it to the MST
    //             vis[node]=1;
    //             sum+=wt;
    //             for(auto it: adj[node]){
    //                 int adjnode = it[0];
    //                 int edw = it[1];
    //                 if(!vis[adjnode]){
    //                     pq.push({edw, adjnode});
    //                 }
    //             }
    //         }
    //     }
    //     return sum;
    // }
    
    
    // KRUSKAL'S ALGO
      int spanningTree(int V, vector<vector<int>> adj[]){
          vector<pair <int , pair <int,int>>> edges; 
          for(int i=0; i<V; i++){
              for(auto it: adj[i]){
                  int adjnode = it[0];
                  int wt = it[1];
                  int node = i;
                  
                  edges.push_back({wt,{node, adjnode}});
              }
          }
          sort(edges.begin(), edges.end());
          DisjointSet ds(V);
          
          int mstwt=0;
          for (auto it : edges){
              int wt = it.first;
              int u = it.second.first;
              int v = it.second.second;
              
              if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                  mstwt+=wt;
                  ds.unionBySize(u,v);
              }
          }
          
          return mstwt;
    }
    
    
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends