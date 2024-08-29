class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findupar(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findupar(parent[node]); //path compression
    }

    void unionbyrank(int u, int v) {
        int ulp_u = findupar(u);
        int ulp_v = findupar(v);
        if (ulp_u == ulp_v) {
            // u and v belong to same component
            return;
        }

        if (rank[ulp_u] < rank[ulp_v]) {
            //smaller gets attached to larger
            //rank doesnt change
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]) {
            //smaller gets attached to larger
            //rank doesnt change
            parent[ulp_v] = ulp_u;
        }
        else {
            //attach v to u (or vice versa)
            //incease rank of u by 1 (or vice versa)
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionbysize(int u, int v) {
        int ulp_u = findupar(u);
        int ulp_v = findupar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
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
    int removeStones(vector<vector<int>>& stones)  {
        int n = stones.size();
        int maxr = 0;
        int maxc = 0;
        
        for(auto it: stones){
            maxr = max(it[0], maxr);
            maxc = max(it[1], maxc);
        }
        
        DisjointSet ds(maxr + maxc + 1);
        
        unordered_map<int, int> rownode ;
        int temp = maxc; // 0 1 2 3 is taken
        
        for(int i=0; i<=maxr ; i++ ){
            rownode[i]= temp+1; // 0 -> 4 , 1 -> 5 and so on
            temp++;
        }
        
        for(auto it: stones){
            int srow = it[0];
            int scol = it[1];

            if(ds.findupar(scol)!=ds.findupar(rownode[srow])) {
                ds.unionbyrank(scol, rownode[srow]);
            }
        }
        
        unordered_set<int> ulps;
        for(auto it: stones){
            int srow = it[0];
            int scol = it[1];
            ulps.insert(ds.findupar(rownode[srow]));
            ulps.insert(ds.findupar(scol));
        }
        int cnt = ulps.size();
        return n-cnt;
    }
};