class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        queue<pair<int, pair<int,int>>> q;
        q.push({0,{src,0}});
        
        vector<int> dist(n , 1e9);
        dist[src]=0;
        
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            
            if(stops > K){
                continue;
            }
            for(auto it: adj[node]){
                int adjnode = it.first;
                int edw = it.second;
                
                if(cost + edw < dist[adjnode] && stops<=K){
                    dist[adjnode]= cost + edw;
                    q.push({stops+1, { adjnode,  dist[adjnode]}});
                }
            }
        }
        
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
        
    }
};