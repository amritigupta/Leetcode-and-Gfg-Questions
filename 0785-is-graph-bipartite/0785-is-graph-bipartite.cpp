class Solution {
  public:
    bool coloring(vector<vector<int>>& graph, int i, vector<int>& color, int to_color){
        
        if (color[i]== to_color)return true;
        if (color[i] == 1-to_color)return false;
        
        color[i]= to_color;
        for (int it=0; it<graph[i].size(); it++){
            if (coloring(graph,graph[i][it],color,1-to_color)==false)return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v= graph.size();
        vector<int> color(v,-1);
        for (int i=0; i<v; i++){
            if (color[i]==-1){
                if(coloring(graph,i,color,0)==false)return false;
            }
        }
        return true;
    }
};