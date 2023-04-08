class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
       
        
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        
        vector<vector<int>> dist(n, vector<int> (m,1e5));
        queue<pair< pair<int,int> , int >> q;
        for (int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({{i,j},0});
                }
            }
        }
        
        
        // BRUTE FORCE
//         // ROUND 1
//         int flag=0;
//         for (int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(mat[i][j]==1){
//                     int dis=1e5;
//                     for(int k=0; k<4; k++){
//                         int nrow = i + drow[k];
//                         int ncol= j+ dcol[k];
//                         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m) dis = min(dis, dist[nrow][ncol]+1);
//                     }
//                     dist[i][j]=dis;
//                     if(dis==1e5){
//                         flag=1;
//                     }
//                 }
//             }
//         }
        
        
//         //FURTHER ROUNDS 
//         while(flag!=0){
//         for (int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(mat[i][j]==1e5){
//                     int dis=1e5;
                    
//                     for(int k=0; k<4; k++){
//                         int nrow = i + drow[k];
//                         int ncol= j+ dcol[k];
//                         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)  dis = min(dis, dist[nrow][ncol] +1 );
//                     }
//                     dist[i][j]=dis;
//                     if(dis==1e5){
//                         flag=1;
//                     }
//                 }
//             }
//            }
//         }
        

       //BFS
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            for (int i=0; i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                
                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && dist[nrow][ncol]==1e5){
                    dist[nrow][ncol]=dis+1;
                    q.push({{nrow,ncol},dis+1});
                }
            }
        }
            
        
        return dist;
    }
};