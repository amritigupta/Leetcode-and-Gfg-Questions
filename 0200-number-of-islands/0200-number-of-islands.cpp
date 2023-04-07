class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        int cnt = 0;
        vector<vector<int>> directions {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
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