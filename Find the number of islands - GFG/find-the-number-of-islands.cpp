//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    // int numIslands(vector<vector<char>>& grid) {
    //     // Code here
    //     int n = grid.size();
    //     int m = grid[0].size();
        
    //     int drow[] = {0,-1,0,1,-1,-1,1,1};
    //     int dcol[]= {-1, 0, 1,0,-1,1,-1,1};
        
    //     vector<vector<bool>> vis(n, vector<bool> (m, false));
        
    //     int cnt =0;
    //     for(int i=0; i<n; i++){
    //         for (int j=0; j<m ; j++)
    //           if (!vis[i][j] && grid[i][j]=='1'){
    //             cnt++;
    //             queue<pair<int,int>> q;
    //             q.push({i,j});
    //             vis[i][j]=true;
                
    //             while(!q.empty()){
    //                 int row = q.front().first;
    //                 int col = q.front().second;
    //                 q.pop();
                    
    //                 for(int k=0; k<8; k++){
    //                     int nrow = row + drow[k];
    //                     int ncol = col + dcol[k];
                        
    //                     if (!vis[nrow][ncol] && grid[nrow][ncol]=='1' && nrow>=0 && nrow<n && ncol>=0 && ncol<m){
    //                         q.push({nrow,ncol});
    //                         vis[nrow][ncol]=true;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return cnt;
        
    // }

    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        int cnt = 0;
        vector<vector<int>> directions {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1,1}, {1, -1}, {-1, -1}, {-1, 1}};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    cnt++;
                    visited[i][j] = true;
                    while(q.empty() == false){
                        auto curr = q.front();
                        q.pop();
                        for(auto &e : directions){
                            int newX = curr.first + e[0];
                            int newY = curr.second + e[1];
                            if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == '1' && visited[newX][newY] == false){
                                visited[newX][newY] = true;
                                q.push({newX, newY});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends