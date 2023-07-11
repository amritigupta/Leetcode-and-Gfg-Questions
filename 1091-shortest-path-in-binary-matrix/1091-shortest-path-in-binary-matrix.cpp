class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // no need of pq here
        // priority_queue < pair<int,int> , vector<pair<int,int>> , greater <pair<int,int> >> pq;
        
        queue<pair< int, pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        if(grid[0][0]==1){
            return -1;
        }
        else{
            if(m==1 && n==1){
                return 1;
            }
        }
        
        dist[0][0]=1;
        q.push({1, {0,0}});
        vector<pair<int,int>> dir ={ {0,1} , {1,0}, {-1, 0}, {0, -1}, {1,1}, {-1,-1}, {-1,1}, {1,-1}};
        
        while(!q.empty()){
            
            int dis = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            
            for(int i=0; i<8; i++){
                int newr = r+dir[i].first;
                int newc = c+dir[i].second;
                
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]!=1 && dis+1 < dist[newr][newc]){
                     dist[newr][newc] = 1+dis;
                     if(newr == n-1 && newc == m-1){
                         return dis+1;
                     }
                     q.push({1+dis, {newr, newc}});
                }
            }
        }
        return -1;
    }
};