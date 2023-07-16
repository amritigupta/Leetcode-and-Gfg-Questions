// DSU HELPS IN DYNAMIC MERGING/CONNECTING

class DisjointSet{
    
public:
    vector <int> parent,size;
    
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        
        int n = details.size();
        DisjointSet ds(n);
        unordered_map <string, int> mapmailnode;
        
        for(int i=0; i<n; i++){
            for(int j=1; j<details[i].size(); j++){
                string mail = details[i][j];
                if(mapmailnode.find(mail) == mapmailnode.end()){
                    mapmailnode[mail]=i;
                }
                else{
                    ds.unionBySize(i, mapmailnode[mail]); //map current node and mapmailnode[mail]
                }
          }
        }
        
        vector<string> mergedmail[n];
        for(auto it: mapmailnode){
            string mail = it.first;
            int node = ds.findUltimateParent(it.second);
            mergedmail[node].push_back(mail);
        }
        
        vector<vector<string>>  ans;
        for(int i=0; i<n; i++){
            if(mergedmail[i].size()==0){
                continue;
            }
            
            sort(mergedmail[i].begin(), mergedmail[i].end());
            
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(auto it: mergedmail[i]){
                temp.push_back(it);
            }
            
            ans.push_back(temp);
        }
        return ans;
    }
    
 
};