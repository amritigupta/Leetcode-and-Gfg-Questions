class Solution {
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,1,-1};

    void dfs(int x, int y,vector<vector<char>>& grid, vector<vector<int>> &vis, int n , int m){
        vis[x][y]=1;
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0 && grid[nx][ny]=='1') dfs(nx, ny, grid, vis, n, m);
        }   
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid,vis,n,m);
                }
            }
        }
        return ans;
    }
};