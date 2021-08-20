//O(n^2) time, O(n^2) space

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = board.size();
        unordered_map<int, vector<char>> row(size), col(size), subgrid(size);
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                char val =board[i][j];
                if( val == '.')
                    continue;
                if(find(row[i].begin(), row[i].end(), val) != row[i].end())
                    return false;
                row[i].push_back(val);
                if(find(col[j].begin(), col[j].end(), val) != col[j].end())
                    return false;
                col[j].push_back(val);
                int subgridNo = (i/3)*3 + (j/3);
                if(find(subgrid[subgridNo].begin(), subgrid[subgridNo].end(), val) !=subgrid[subgridNo].end())
                    return false;
                subgrid[subgridNo].push_back(val);
            }
        }
        return true;
    }
};