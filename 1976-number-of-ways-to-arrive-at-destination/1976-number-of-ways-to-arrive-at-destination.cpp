class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<vector<pair<int, int>>> adj(n);
        for(auto &road: roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        vector<long long> distance(n, LONG_MAX);
        vector<int> path(n, 0);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        //push {time, node}
        pq.push({0, 0});
        distance[0] = 0;
        path[0] = 1;
        
        while(!pq.empty()) {
            long long time = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                long long adjnode = it.first;
                long long edw = it.second;
                if(edw + time < distance[adjnode]){
                    distance[adjnode]=time+edw;
                    pq.push({distance[adjnode], adjnode});
                    path[adjnode]=path[node];
                }
                else if(edw + time == distance[adjnode]){
                    path[adjnode]+=path[node];
                    path[adjnode]%=mod;
                }                
            }
        }
        
        return path[n-1];
    }
};