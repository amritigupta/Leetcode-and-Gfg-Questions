class Solution {
    
    //METHOD 1 : DETECT CYCLE USING DFS :: IF A NODE DOESNT HAVE CYCLE THEN IT IS SAFENODE 
//     bool dfs(int node, vector<int> &vis, vector<int> &pathvis, vector<vector<int>>& graph){
//         vis[node]=1;
//         pathvis[node]=1;
 
        
//         for(auto it: graph[node]){
//             if(!vis[it]){
//                 if (dfs(it, vis, pathvis, graph)==true) {
//                     return true; //cycle
//                 }
//             }
//             if(vis[it] && pathvis[it]){
//                 return true; //cycle
//             }
//         }

//         pathvis[node]=0;
//         return false;
//     }
    
    
public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int V = graph.size();
//         vector<int> vis(V,0), pathvis(V,0);
//         vector<int> safenodes;
        
//         for(int i=0; i<V;i++){
//             if(vis[i]==0){
//                 dfs(i, vis, pathvis, graph);
//             }
//         }
//         for(int i=0; i<V; i++){
//             if(pathvis[i]==0){
//                 safenodes.push_back(i);
//             }
//         }
        
//         return safenodes;
//     }
    
    
    // METHOD 2 : KAHN'S ALGO :: SAFENODES ARE THOSE WHICH HAVE OUTDEGREE=0 AND HAVE PATH TO THAT 0 OUTDEGREE NODE
    // WE KNOW KAHN'S ALGO CAN BE USED TO FIND ALL THOSE NODES WITH INDEGREE = 0  AND ALL NODES IN PATH OF IT
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n=graph.size();
	
    vector<int>indegree(n,0); // creating array to store the indegree
	
    vector<vector<int>>adjrev(n); // we will be reversing the edges so that we can apply toposort as toposort work on indegree.
	
    for(int i=0;i<n;i++){
        for(auto it:graph[i]){
            adjrev[it].push_back(i);
            indegree[i]++;
        }
    }
    
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    
        

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adjrev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        sort(topo.begin(), topo.end());
        return topo;
     }

};