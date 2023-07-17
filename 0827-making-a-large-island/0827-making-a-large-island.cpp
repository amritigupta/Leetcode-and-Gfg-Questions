// COMPONENTS == GRAPH
// DYNAMICALLY CHANGING GRAPH == DSU

class DisjointSet{
    
public:
    vector <int> parent, size;
    
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node){
        if (node == parent[node]){
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if(ulp_u==ulp_v){
            return;
        }     

        if(size[ulp_u]< size[ulp_v])  {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        
        
        // STEP1 - CONNECTING COMPONENTS
        for (int row = 0; row<n ; row++){
            for(int col = 0 ; col<n ; col++){
                if (grid[row][col]==0){
                    continue;
                }
                
                for(int i=0 ; i<4; i++){
                    int nrow = row+dr[i];
                    int ncol = col+dc[i];
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                        int nodeno = row*n + col;
                        int adjnodeno = nrow*n + ncol;
                        ds.unionBySize(nodeno, adjnodeno);
                    }
                }
                
            }
        }
        
        //STEP2- BRUTE FORCE :  TRY TO CONVERT EVERY ZERO
        int mx =0;
        for (int row = 0; row<n ; row++){
            
            for(int col = 0 ; col<n ; col++){
                if (grid[row][col]==1){
                    continue;
                }
                
                set<int> components;
                
                for(int i=0 ; i<4; i++){
                    int nrow = row+dr[i];
                    int ncol = col+dc[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){
                        if(grid[nrow][ncol]==1){
                            components.insert(ds.findUltimateParent(nrow*n + ncol));
                        }
                    }
                }
                
                int size = 1; //1 because of the zero being converted to one
                for (auto it: components){
                    size += ds.size[it];
                }
                
                mx = max(size, mx);
            }
        }    
        
        
        for(int cellno =0; cellno<n*n ; cellno++){
            mx = max(mx, ds.size[ds.findUltimateParent(cellno)]);
        }
        
        return mx;
    }
};