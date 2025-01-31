class Solution {
    vector<int> size;
    vector<int> parent;
public:
    int findupar(int v){
        if(parent[v]==v) return v;
        else return parent[v]=findupar(parent[v]);
    }

    void Union(int i, int j){
        int upri=findupar(i);
        int uprj=findupar(j);
        if(upri==uprj) return;
        else{
            if(size[upri]<size[uprj]){
                parent[upri]=uprj;
                size[uprj]+=size[upri];
            }
            else{
                parent[uprj]=upri;
                size[upri]+=size[uprj];                
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        size.resize(n);
        
        for(int i=0; i<n; i++){
            parent[i]=i;
            size[i]=1;
        }

        unordered_map<int,vector<int>> row2stone;
        unordered_map<int,vector<int>> col2stone;

        for(int i=0; i<n; i++){
            row2stone[stones[i][0]].push_back(i);
            col2stone[stones[i][1]].push_back(i);
        }

        for(auto it: row2stone){
            vector<int> x = it.second;
            int u = x[0];
            for(int i=1; i<x.size(); i++){
                int v = x[i];
                Union(u, v);
            }
        }

        for(auto it: col2stone){
            vector<int> x = it.second;
            int u = x[0];
            for(int i=1; i<x.size(); i++){
                int v = x[i];
                Union(u, v);
            }
        }

        int comp=0;

        for(int i=0; i<n; i++){
            if(findupar(i)==i) comp++;
        }

        return n-comp;

    }
};