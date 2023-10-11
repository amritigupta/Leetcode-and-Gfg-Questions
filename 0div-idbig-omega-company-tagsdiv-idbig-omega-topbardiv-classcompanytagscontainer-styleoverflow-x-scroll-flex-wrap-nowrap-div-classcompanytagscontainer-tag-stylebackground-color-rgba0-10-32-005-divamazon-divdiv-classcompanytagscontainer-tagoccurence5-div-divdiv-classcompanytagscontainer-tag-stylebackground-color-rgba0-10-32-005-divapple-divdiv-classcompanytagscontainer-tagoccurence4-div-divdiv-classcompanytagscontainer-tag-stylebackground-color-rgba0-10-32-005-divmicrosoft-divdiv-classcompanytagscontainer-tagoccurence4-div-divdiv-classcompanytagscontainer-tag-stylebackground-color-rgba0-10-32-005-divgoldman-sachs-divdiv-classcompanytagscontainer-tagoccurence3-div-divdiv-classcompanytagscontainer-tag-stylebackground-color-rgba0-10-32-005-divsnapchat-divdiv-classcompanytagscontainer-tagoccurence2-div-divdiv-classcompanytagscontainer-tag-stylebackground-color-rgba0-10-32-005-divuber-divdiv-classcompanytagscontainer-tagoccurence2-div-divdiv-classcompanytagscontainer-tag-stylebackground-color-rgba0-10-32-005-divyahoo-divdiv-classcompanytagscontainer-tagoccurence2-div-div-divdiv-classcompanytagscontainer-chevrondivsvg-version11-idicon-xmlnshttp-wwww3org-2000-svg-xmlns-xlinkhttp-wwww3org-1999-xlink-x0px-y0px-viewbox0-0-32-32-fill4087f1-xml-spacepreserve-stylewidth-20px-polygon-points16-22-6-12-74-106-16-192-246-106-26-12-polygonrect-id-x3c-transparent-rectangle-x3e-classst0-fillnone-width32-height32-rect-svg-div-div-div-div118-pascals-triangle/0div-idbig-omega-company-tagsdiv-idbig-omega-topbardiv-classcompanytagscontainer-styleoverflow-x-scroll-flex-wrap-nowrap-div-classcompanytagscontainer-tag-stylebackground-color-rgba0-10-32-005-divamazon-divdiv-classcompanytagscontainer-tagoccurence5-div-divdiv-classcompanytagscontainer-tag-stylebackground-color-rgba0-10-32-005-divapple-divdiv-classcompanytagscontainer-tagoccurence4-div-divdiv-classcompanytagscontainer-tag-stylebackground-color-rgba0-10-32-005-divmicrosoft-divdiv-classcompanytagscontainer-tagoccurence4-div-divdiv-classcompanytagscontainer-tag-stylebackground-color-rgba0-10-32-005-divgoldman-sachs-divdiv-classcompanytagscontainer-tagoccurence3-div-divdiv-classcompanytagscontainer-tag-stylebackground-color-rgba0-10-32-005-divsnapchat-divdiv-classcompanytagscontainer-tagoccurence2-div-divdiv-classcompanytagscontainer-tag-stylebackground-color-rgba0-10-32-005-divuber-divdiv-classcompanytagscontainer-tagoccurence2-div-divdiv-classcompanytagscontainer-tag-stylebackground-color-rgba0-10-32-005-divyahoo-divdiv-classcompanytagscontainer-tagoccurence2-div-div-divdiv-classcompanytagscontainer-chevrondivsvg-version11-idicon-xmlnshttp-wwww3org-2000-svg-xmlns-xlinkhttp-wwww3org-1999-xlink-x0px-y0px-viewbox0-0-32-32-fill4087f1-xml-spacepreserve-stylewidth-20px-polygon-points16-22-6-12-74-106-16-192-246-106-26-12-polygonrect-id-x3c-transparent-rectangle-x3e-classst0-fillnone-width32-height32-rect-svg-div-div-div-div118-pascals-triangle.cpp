class Solution {
    vector<int> generateRow (int row){
        int ans = 1;
        vector<int> ansrow;
        ansrow.push_back(1);
        for(int col = 1 ; col< row ; col++){
            ans = ans * (row - col);
            ans = ans / col;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int i=1; i<=numRows; i++){
            vector<int> temp;
            temp=generateRow(i);
            v.push_back(temp);
        }
        
        return v;
    }
};