class Solution {
//     [[1,10,6,7,9,10,4,9]]
//     n = 1
//     m = 8
    
    
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0]=0;
        
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0,0}});
        
        while(!pq.empty()){
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            if(r==n-1 && c==m-1){
                return diff;
            }
            for(int k=0; k<4; k++){
                int newr = r+dr[k];
                int newc = c+dc[k];
                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    int neweffort = max( abs(grid[r][c]- grid[newr][newc]), diff);
                    if(neweffort < dist[newr][newc]){
                        dist[newr][newc] = neweffort;
                        pq.push({neweffort, {newr, newc}});
                    }
                }
                    
                }
            }
         return 0;
    }
};