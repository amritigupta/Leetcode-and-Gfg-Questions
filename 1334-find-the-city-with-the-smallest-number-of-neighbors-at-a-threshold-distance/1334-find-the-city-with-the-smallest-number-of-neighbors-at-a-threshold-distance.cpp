class Solution {
public:
    vector<pair<int,int>> adj[101];
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(auto x:edges)
        {
            adj[x[0]].push_back({x[2],x[1]});
            adj[x[1]].push_back({x[2],x[0]});
        }
        int res=0;
        int m=n;
        for(int i=0;i<n;i++)
        {
            int c=fun(n,i,distanceThreshold);
            if(c<=m)
            {
                m=c;
                res=i;
            }
        }
        return res;
    }
    
    int fun(int n,int src,int d)
    {
        vector<int> v(n,INT_MAX);
        v[src]=0;
        
        priority_queue<pair<int,int>> pq;
        pq.push({0,src});
        
        while(!pq.empty())
        {
            int w=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(w > v[node])
                continue;
            
            for(auto x:adj[node])
            {
                if(v[x.second] > w+x.first)
                {
                    v[x.second]=w+x.first;
                    pq.push({v[x.second],x.second});
                }
            }
        }
        int c=0;
        for(auto x:v)
        {
            if(x!=INT_MAX && x<=d)
                c++;
        }
        return c;
    }
};