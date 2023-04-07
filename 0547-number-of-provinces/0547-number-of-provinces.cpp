class Solution {
    public: 
    void dfs(int root, vector<int>& vis, vector<int> adj[]){
        if (vis[root])
            return;
        
        
        vis[root]=1;
        for (auto val : adj[root]){
            dfs(val,vis,adj);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        //undirected graph
        int n= isConnected.size();
        
        int cnt=0;
        
        vector<int> vis(n+1,0);
        
        // create adjacency list:
        vector<int> adj[n+1];
        
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i!=j && isConnected[i][j]){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        
        
        for (int i=1; i<=n; i++){
            if(!vis[i]){
                cnt++;
                queue<int> q;
                
                // dfs(i,vis,adj);
                // cnt++;
                
                q.push(i);
                vis[i]=1;
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for (auto it: adj[node]){
                        if (!vis[it]){
                            vis[it]=1;
                        q.push(it);}
                    }
                }
                
            }
        }
        return cnt;
    }
    
//    int findCircleNum(vector<vector<int>>& isConnected) {
// 		int V=isConnected.size();
// 		vector<int>adjls[V];
// 		for(int i=0; i<V; i++){
// 			for(int j=0; j<V; j++){
// 				if(isConnected[i][j]==1 && i!=j){
// 					adjls[i].push_back(j);
// 					adjls[j].push_back(i);
// 				}
// 			}
// 		}
       
       
// 		vector<int>v(V, 0); //visited array
       
// 		int cnt=0;
// 		for(int i=0; i<V; i++){
// 			if(v[i]==0){
// 				cnt++;
// 				queue<int>q;
// 				q.push(i);
// 				while(!q.empty()){
// 					int ft=q.front();
// 					q.pop();
// 					for(auto it: adjls[ft]){
// 						if(!v[it]){
// 							v[it]=1;
// 							q.push(it);
// 						}
// 					}
// 				}
// 			}
// 		}
// 		return cnt;
// 	}
    
};