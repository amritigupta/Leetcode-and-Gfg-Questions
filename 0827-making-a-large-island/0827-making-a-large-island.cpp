class Solution {
public:
    vector<int> size;
    vector<int> parent;

    vector<int> di={-1,1,0,0};
    vector<int> dj={0,0,-1,1};

    int findupar(int v){
        if(parent[v]==v){
            return v;
        }
        else return parent[v]=findupar(parent[v]);
    }

    void Union(int u, int v){
        int ulpu = findupar(u);
        int ulpv = findupar(v);
        if(ulpu!=ulpv){
            if(size[ulpu]<size[ulpv]){
                size[ulpv]+=size[ulpu];
                parent[ulpu]=ulpv;
            }
            else{
                size[ulpu]+=size[ulpv];
                parent[ulpv]=ulpu;
            }
        }
    }

    bool isvalid(int x, int y, int n){
        if(x>=0 && x<n && y>=0 && y<n) return true;
        return false;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int n){

        vis[i][j]=1;

        for(int k=0; k<4; k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(isvalid(ni,nj,n) && grid[ni][nj]==1 && vis[ni][nj]==0){
                Union(n*i+j, n*ni+nj);
                dfs(ni, nj, grid, vis, n);
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        size.resize(n*n);
        parent.resize(n*n);
        bool all1sflag=true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                size[i*n + j]=1;
                parent[i*n+j]=i*n+j;
                if(grid[i][j]==0){
                    all1sflag=false;
                }
            }
        }

        if(all1sflag) return n*n;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    dfs(i, j, grid, vis, n);
                }
            }
        }

        int maxi=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    int mx=1;
                    unordered_set<int> st;
                    for(int k=0; k<4; k++){
                        int ni=i+di[k];
                        int nj=j+dj[k];
                        if(isvalid(ni,nj,n) && grid[ni][nj]==1){
                            // cout<<ni<<" "<<nj<<endl;      

                            int upar=findupar(ni*n+nj);

                            // cout<<upar<<endl;
                            // cout<<size[upar]<<endl;
                            
                            if(st.count(upar)==0) mx+=size[upar];
                            st.insert(upar);
                        }
                    }
                    maxi=max(mx, maxi);
                    cout<<maxi<<endl;
                }
            }
        }     

        // int x=0;
        // for(auto it: size){
        //     cout<<x<<" "<<it<<endl;
        //     x++;
        // }


        // x=0;
        // for(auto it: parent){
        //     cout<<x<<" "<<it<<endl;
        //     x++;
        // }

        return maxi;

    }
};