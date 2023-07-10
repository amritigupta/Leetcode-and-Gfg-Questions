class Solution {
public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();
       
//         int drow[]={0,-1,0,1};
//         int dcol[]={-1,0,1,0};
        
//         vector<vector<int>> dist(n, vector<int> (m,1e5));
//         queue<pair< pair<int,int> , int >> q;
        
//         for (int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(mat[i][j]==0){
//                     dist[i][j]=0;
//                     q.push({{i,j},0});
//                 }
//             }
//         }
        
//         while(!q.empty()){
//             int row = q.front().first.first;
//             int col = q.front().first.second;
//             int dis = q.front().second;
//             q.pop();
//             for (int i=0; i<4;i++){
//                 int nrow = row+drow[i];
//                 int ncol = col+dcol[i];
                
//                 if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && dist[nrow][ncol]==1e5){
//                     dist[nrow][ncol]=dis+1;
//                     q.push({{nrow,ncol},dis+1});
//                 }
//             }
//         }
            
        
//         return dist;
//     }
    
    
    // METHOD 2
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (mat[r][c] == 0) q.push({r, c});
                else mat[r][c] = -1; // Marked as not processed yet!
           
        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};
        while (!q.empty()) {
            auto [r, c] = q.front(); 
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr < 0 || nr == m || nc < 0 || nc == n || mat[nr][nc] != -1) continue;
                mat[nr][nc] = mat[r][c] + 1;
                q.push({nr, nc});
            }
        }
        return mat;
    }
};