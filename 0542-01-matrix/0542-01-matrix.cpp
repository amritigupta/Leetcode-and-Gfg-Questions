class Solution {
    vector<int> di = {-1,1,0,0};
    vector<int> dj = {0,0,-1,1};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e6));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i, j});
                }
            }
        }

        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            steps++;
            for(int l=0; l<sz; l++){
                int i = q.front().first;
                int j = q.front().second;
                cout<<i<<" "<<j<<endl;
                q.pop();

                for(int k=0; k<4; k++){
                    int ni = i+di[k];
                    int nj = j+dj[k];
                    // if(ni>=0 && ni<n && nj>=0 && nj<m) cout<<ni<<" "<<nj<<" "<<dist[ni][nj]<<endl;
                    if(ni>=0 && ni<n && nj>=0 && nj<m && dist[ni][nj]==1e6){
                        dist[ni][nj]=steps;
                        q.push({ni,nj});
                    }
                }

            }
        }

        return dist;

    }
};