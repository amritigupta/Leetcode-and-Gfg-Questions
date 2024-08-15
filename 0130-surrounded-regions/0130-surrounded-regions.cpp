class Solution {
    vector<int> di = {-1,1,0,0};
    vector<int> dj = {0,0,-1,1};

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            if(board[i][0]=='O'){
                q.push({i, 0});
            }
            if(board[i][m-1]=='O'){
                q.push({i, m-1});
            }
        }

        for(int j=1; j<m-1; j++){
            if(board[0][j]=='O'){
                q.push({0,j});
            }
            if(board[n-1][j]=='O'){
                q.push({n-1, j});
            }
        }


        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;
                board[i][j]='.'; //this marks it as visited O on boundary or connnected to such O
                q.pop();

                for(int k=0; k<4; k++){
                    int ni = i+di[k];
                    int nj = j+dj[k];

                    if(ni>=0 && ni<n && nj>=0 && nj<m && board[ni][nj]=='O'){
                        q.push({ni,nj});
                    }
                }
            }
        }


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='.'){
                    board[i][j]='O';
                }
            }
        }

        return;
    }
};