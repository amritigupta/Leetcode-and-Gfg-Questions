class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int count=0;
        queue< pair<pair<int,int>,int> > q;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,1,-1};
        int oranges=0;
   
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!=0){
                    oranges++;
                }
                if(grid[i][j]==2){
                    count++;
                    q.push({{i,j},0});
                }
            }
        }
        
        int maxi=0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            maxi=max(time,maxi);
            q.pop();
            
            for(int k=0; k<4; k++){
                int newr = r+dr[k];
                int newc = c+dc[k];
                
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 ){
                    count++;
                    grid[newr][newc]=2;
                    q.push({{newr,newc},time+1});
                }
            }
        }
        
        if(count==oranges){
            return maxi;
        }
        else return -1;
    }
};