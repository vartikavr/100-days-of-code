//O(size(ops)) time, O(1) space

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int commonRows = m, commonCols = n;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i][0] < commonRows && ops[i][1] < commonCols)
            {
                commonRows = ops[i][0];
                commonCols = ops[i][1];
            }
            else if(ops[i][0] < commonRows)
                commonRows = ops[i][0];
            else if(ops[i][1] < commonCols)
                commonCols = ops[i][1];
        }
        return commonRows*commonCols;
    }
};