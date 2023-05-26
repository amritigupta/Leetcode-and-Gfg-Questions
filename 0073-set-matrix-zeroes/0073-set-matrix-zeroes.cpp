class Solution {
public:
    // O(M+N) SPACE COMPLEXITY
    
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size(); //nrows
//         int m = matrix[0].size(); //ncols
        
//         vector<int> row(n,0);
//         vector<int> col(m,0);
        
//         for(int i=0;i<n;i++){
//             for(int j=0; j<m; j++){
                
//                 if (matrix[i][j]==0){
//                     row[i]=1;
//                     col[j]=1;
//                 }
                
//             }
//         }
        
//         for(int i=0;i<n;i++){
//             for(int j=0; j<m; j++){
                
//                 if(row[i] == 1 || col[j] == 1){
//                     matrix[i][j]=0;
//                 }
                
//             }
//         }        
//     }
    
    
    // 0{1} SPACE COMPLEXITY
void setZeroes(vector<vector<int> > &matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        //J=0
        if (matrix[i][0] == 0) col0 = 0;
        
        //J!=0
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        //J!=0
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        
        //J==0
        if (col0 == 0) matrix[i][0] = 0;
    }
}
};