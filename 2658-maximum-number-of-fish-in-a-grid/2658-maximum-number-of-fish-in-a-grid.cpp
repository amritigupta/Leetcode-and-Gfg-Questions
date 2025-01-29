class Solution {
    vector<int> di = {-1,1,0,0};
    vector<int> dj={0,0,1,-1};
public:
    bool isvalid(int x, int y, int n, int m){
        if(x>=0 && y>=0 && x<n && y<m) return true;
        return false;
    }

    int bfs(int i, int j, vector<vector<int>>& grid, int n, int m){
        cout<<i<<" "<<j<<endl;
        int x = 0;
        x+=grid[i][j];
        grid[i][j]=0;

        for(int k=0; k<4; k++){
            int ni = i+di[k];
            int nj= j+dj[k];
            if(isvalid(ni, nj, n, m) && (grid[ni][nj]>0)) x+=bfs(ni,nj,grid,n,m);
        }

        return x;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]>0){ //water and unvisited cell
                    ans = max(ans,bfs(i,j,grid,n,m));
                }
            }
        }
        return ans;
    }
};