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
        vector<long long> ways(n, 0);
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        
        //push {time, node}
        pq.push({0, 0});
        distance[0] = 0;
        ways[0] = 1;
        
        while(!pq.empty()) {
            long long time = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                long long adjnode = it.first;
                long long edgew = it.second;
                if(edgew+time < distance[adjnode]){
                    distance[adjnode]=edgew+time;
                    ways[adjnode] = ways[node];
                    pq.push({distance[adjnode], adjnode});
                }
                else if(edgew+ time == distance[adjnode]){
                    ways[adjnode] += ways[node];
                    ways[adjnode]%=mod;
                }
            }
        }
        
        return ways[n-1];
    }
};