//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
vector<pair<int, int>> bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int a, int b) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        
        vis[i][j]=1;
        q.push({i,j});
        
        vector<int> dRow{-1,0,1,0};
        vector<int> dCol{0, 1, 0, -1};
        
        vector<pair<int, int>> ans;
        
        while(!q.empty()) {
            
            int r=q.front().first;
            int c=q.front().second;
            ans.push_back({r-a, c-b});
            q.pop();
            
            for(int i=0;i<4;i++) {
                int nRow=dRow[i]+r;
                int nCol=dCol[i]+c;
                if(nRow>=0&&nRow<n&&nCol>=0&&nCol<m&&grid[nRow][nCol]==1&&!vis[nRow][nCol]) {
                    vis[nRow][nCol]=1;
                    q.push({nRow, nCol});
                }
            }
        }
        
        return ans;
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        set<vector<pair<int, int>>> st;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1 && !vis[i][j]) {
                    vector<pair<int,int>> ans;
                    ans=bfs(i, j, grid, vis, i, j);
                    st.insert(ans);
                    
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends