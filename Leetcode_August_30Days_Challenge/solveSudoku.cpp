//O(9^(n*n)) time

class Solution {
public:
    bool isSafe(int i, int j, int n, vector<vector<char>> &board)
    {
        char val= n+'0';
        for(int k=0;k<9;k++)
            if(board[i][k]==val || board[k][j]==val)
                return false;
        int rowSubgrid = i-i%3;
        int colSubgrid = j-j%3;
        for(int p=0;p<3;p++)
        {
            for(int q=0;q<3;q++)
                if(board[p+rowSubgrid][q+colSubgrid]==val)
                    return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        int i, j;
        for(i=0;i<9;i++)
        {
            int flag = 0;
            for(j=0;j<9;j++)
            {
                if(board[i][j] == '.'){
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(i==9 && j==9)
            return true;
        for(int k=1;k<=9;k++)
        {
            if(isSafe(i, j, k, board))
            {
                board[i][j] = k+'0';
                if(solve(board))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};