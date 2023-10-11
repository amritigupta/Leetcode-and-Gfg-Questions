class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int count=0; // number of elements inserted in ans array to check if it is greater than n*m i.e. total number of elements in matrix
        int top = 0, down=n-1, left=0, right=m-1;
        
        while(count<n*m){
            for(int i=left; i<=right and count<n*m ; i++){
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            
            for(int i=top; i<=down and count<n*m ; i++){
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;
            
            for(int i=right; i>=left and count<n*m ; i--){
                ans.push_back(matrix[down][i]);
                count++;
            }
            down--;
            
            for(int i=down; i>=top and count<n*m ; i--){
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }
        
        return ans;
    }
};