class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int first_row0 = false, first_col0 = false;
        //Consider first row and first columnas dummy row and column
        //We use these dummy row and column to store the state of a row or column
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    if(i == 0)
                        first_row0 = true; //Checking whether entire dummy row would be zero
                    if(j == 0)
                        first_col0 = true; //Checking whether entire dummy column would be zero
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        //Traverse from (1,1) to (rows-1, cols-1) or vice-versa
        //This would ensure we don not currently effect the dummy rows and columns
        for(int i = rows - 1; i >= 1; i--) {
            for(int j = cols - 1; j >= 1; j--) {
                if(matrix[i][0] == 0 or matrix[0][j] == 0 )
                    matrix[i][j] = 0;
            }
        }
        
        //Now we handle the dummy row and column
        if(first_row0 == true) {
            //Make the entire first row zero
            for(int i = 0; i < cols; i++) {
                matrix[0][i] = 0;
            }
        }
        if(first_col0 == true) {
            //Make the entire first column zero
            for(int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};