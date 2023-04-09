class Solution {

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerq) {
        vector<int> adj[numCourses];
        for (int i=0 ; i<prerq.size(); i++){
            adj[prerq[i][1]].push_back(prerq[i][0]);
        }
        
        int V = numCourses;
        queue<int> q;
        vector<int> indegree(V,0);
        
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        for (int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(topo.size()==V){return topo;}
        return {};
    }
};