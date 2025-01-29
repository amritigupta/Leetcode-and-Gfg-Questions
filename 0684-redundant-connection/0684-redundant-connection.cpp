class Solution {
public: 
    vector<int> rank;
    vector<int> parent;

    void Union(int u, int v){
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
    }

    int findpar(int v){
        if(parent[v]==v) return v;

        return parent[v]=findpar(parent[v]); //path compression
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();  // n = 5, nodes from 1 to 5, so vectors resized to n+1
        rank.resize(n+1);
        parent.resize(n+1);
        vector<int> v;

        for(int i=1; i<=n; i++){
            parent[i]=i;
            rank[i]=0;
        }


        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];

            int para= findpar(a);
            int parb = findpar(b);

            if(para==parb){
                v={a,b};
                continue;
            }
            Union(para, parb);
        }

        return v;
    }
};