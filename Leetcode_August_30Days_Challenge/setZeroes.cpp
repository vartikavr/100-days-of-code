//O(mn) time, where m is number of rows, n is the number of columns

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool isFirstCol = false;
        for(int i=0;i<rows;i++)
        {
            if(matrix[i][0] == 0)
                isFirstCol = true;
            for(int j=1;j<cols;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<rows;i++)
            for(int j=1;j<cols;j++)
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j] = 0;
        //for first row
        if(matrix[0][0] == 0)
        {
            for(int j=1;j<cols;j++)
                matrix[0][j] = 0;
        }
        //for first column
        if(isFirstCol)
        {
            for(int i=0;i<rows;i++)
                matrix[i][0]=0;
        }
    }
};