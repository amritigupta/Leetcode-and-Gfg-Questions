class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector <int> pathvis) {
        vis[node] = 1;
        pathvis[node]=1;
        for (auto it: adj[node]) {
            if (vis[it] == 0) {
                if (dfs(it, adj, vis,pathvis) == true)
                    return true;
            } else if (vis[it] == 1 && pathvis[it]==1) {
                return true;
            }
        }
        pathvis[node] = 0; 
        return false;  
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector <int> vis(numCourses, 0);
        vector <int> pathvis(numCourses, 0);
        vector <int> adj[numCourses];
        for (int i = 0; i < n; i++) 
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfs(i, adj, vis,pathvis) == true)
                    return false;
            }
        }
        return true;
    }
};