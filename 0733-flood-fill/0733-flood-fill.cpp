class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        

        vis[sr][sc]=1;
        vector<vector<int>> image1= image;
        image1[sr][sc]=color;
        
        queue<pair<pair<int,int>,int>> q;
        
        q.push({{sr,sc}, image[sr][sc]});
        
        int drow[] = {0,-1,0,1};
        int dcol[]= {-1, 0,1,0};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int c = q.front().second;
            q.pop();
            
            for (int i=0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                
                if ( nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]  && image[nrow][ncol]==c){
                    vis[nrow][ncol]=1;
                    image1[nrow][ncol]=color;
                    q.push({{nrow,ncol},c} );
                }
            }
        }
        
        return image1;
    }
};