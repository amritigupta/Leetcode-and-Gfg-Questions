class Solution {
public:
    
    // IN EXTRA SPACE
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int ans[n][n];
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
                
//                 ans[j][n-i-1] = matrix[i][j];           
//             }
//         }
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){         
//                 matrix[i][j]= ans[i][j];        
//             }
//         }
//     }
    
    // IN O(1) SPACE
    // take transpose then reverse every row
    
     void rotate(vector<vector<int>>& matrix) {
         int n = matrix.size();
         //taking transpose
         for(int i=0; i<=n-2; i++){
             for(int j=i+1; j<=n-1; j++){
                 swap(matrix[i][j], matrix[j][i]);
             }
         }
         
         //reversing all rows
         for(int i=0; i<n; i++){
             reverse(matrix[i].begin(), matrix[i].end());
         }
     }
};