class Solution {
    vector<int>parent;
    int find(int x) {
        if(parent[x]==x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int c = connections.size();
        if (n-1 > c) return -1;
        int extra=0;
        
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (int i = 0; i < c; i++) {
            int x = find(connections[i][0]);
            int y = find(connections[i][1]);
            if (x != y) parent[y] = x;
            if(x==y) extra++; //same parent 
        }
        
        
        // ans stores number of connected components 
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                ans++;
        
        if(extra>=ans-1) return ans-1;
        else{
            return -1;
        }
    }
};
