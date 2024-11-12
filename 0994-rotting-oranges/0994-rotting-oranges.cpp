class Solution {
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,1,-1};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        int ans = -1;
        while(!q.empty()){
            int sz = q.size();
            ans++;
            for(int i=0; i<sz; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(ans==-1) return 0;
        return ans;
    }
};