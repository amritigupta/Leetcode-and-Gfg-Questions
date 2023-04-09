class Solution {
    bool dfs(int node, vector<int> &vis, vector<int> &pathvis, vector<vector<int>>& graph, vector<int> &check){
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        
        for(auto it: graph[node]){
            if(!vis[it]){
                if (dfs(it, vis, pathvis, graph,check)==true) {
                    check[node]=0;
                    return true;
                }
            }
            if(vis[it] && pathvis[it]){
                check[node]=0;
                return true; //cycle
            }
        }
        
        check[node]=1; //safe
        pathvis[node]=0;
        return false;
    }
    
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V,0), pathvis(V,0);
        vector<int> safenodes;
        vector<int> check(V,0);
        
        for(int i=0; i<V;i++){
            if(vis[i]==0){
                dfs(i, vis, pathvis, graph, check);
            }
        }
        for(int i=0; i<V; i++){
            if(check[i]==1){
                safenodes.push_back(i);
            }
        }
        
        return safenodes;
    }
};