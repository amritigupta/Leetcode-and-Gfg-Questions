class Solution {
private:
    bool isSafe(vector<vector<char>>& board, int row, int col)
    {
        int i = row - 1, j = col - 1, k = col + 1;
        while(i >= 0)
        {
            if(board[i][col] == 'Q') return false;
            if(j >= 0 && board[i][j] == 'Q') return false;
            if(k < board.size() && board[i][k] == 'Q') return false;
            i--;
            j--;
            k++;
        }
        
        return true;
    }

    void nQueens(vector<vector<char>>& board, int row, int& ans)
    {
        if(row == board.size()) 
        {
            ans++;
            return;
        }

        for(int col = 0; col < board.size(); col++)
        {
            if(isSafe(board, row, col))
            {
                board[row][col] = 'Q';
                nQueens(board, row + 1, ans);
                board[row][col] = '#';
            }
        }
    }

public:
    
    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '#'));
        int answer = 0;
        nQueens(board, 0, answer);
        return answer;
    }
    
};