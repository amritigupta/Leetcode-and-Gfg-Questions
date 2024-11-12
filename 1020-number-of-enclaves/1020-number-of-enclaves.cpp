class Solution {
    vector<int> di = {-1,1,0,0};
    vector<int> dj = {0,0,-1,1};

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            if(grid[i][0]==1){
                grid[i][0]=2;
                q.push({i,0});
            }
            if(grid[i][m-1]==1){
                grid[i][m-1]=2;
                q.push({i, m-1});
            }
        }

        for(int j=0; j<m; j++){
            if(grid[0][j]==1){
                grid[0][j]=2;
                q.push({0, j});
            }
            if(grid[n-1][j]==1){
                grid[n-1][j]=2;
                q.push({n-1, j});
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            
            q.pop();

            for(int k=0; k<4; k++){
                int ni = i+di[k];
                int nj = j+dj[k];

                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                    grid[ni][nj]=2;
                    q.push({ni,nj});
                }
            }
        }

        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};