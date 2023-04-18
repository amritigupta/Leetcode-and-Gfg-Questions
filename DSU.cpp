#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY IS O(4*ALPHA) == O(CONSTANT)

class DisjointSet{
    vector <int> rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0 );
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

    void unionByRank(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if(ulp_u==ulp_v){
            return;
        }

        if(rank[ulp_u]< rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }

        else if (rank[ulp_v]< rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }

        else { //if same rank 
            parent[ulp_v] = ulp_u; // v attached to u
            rank[ulp_u]++; //larger one grows in size
        }
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

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2 , 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if (ds.findUltimateParent(3)== ds.findUltimateParent(7)){
        cout << "Same\n";
    }
    else{
        cout << "Not same \n";
    }

    ds.unionByRank(3, 7);

    if (ds.findUltimateParent(3)== ds.findUltimateParent(7)){
        cout << "Same\n";
    }
    else{
        cout << "Not same \n";
    }
    return 0;
}