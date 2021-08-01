//O(n^2) time

class Solution {
public:
    int valid(int n, int i, int j)
    {
        //check for correct value of i and j and check if already visited
        if(i<0 || j<0 || i>=n || j>=n)
            return 0;
        return 1;
    }
    vector<pair<int, int>> neighbour(int n, int i, int j)
    {
        vector<pair<int,int>> res;
        int row[4] = {-1, 0, 1, 0};
        int col[4] = {0, -1, 0, 1};
        for(int k=0;k<4;k++)
        {
            if(valid(n, i + row[k], j + col[k]))
                res.push_back({i+row[k], j+col[k]});
        }
        return res;
    }
    int dfs(vector<vector<int>> &grid, int row, int col, int color)
    {
        int currArea = 0;
        grid[row][col] = color;
        for(auto p : neighbour(grid.size(), row, col))
        {
            if(grid[p.first][p.second] == 1)
                currArea += dfs(grid, p.first, p.second, color);
        }
        return currArea + 1;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int, int> area;
        int index = 2; 
        int maxArea = 0; //store area of max 1s islands when 0 not inverted
        //assign different color to all connected 1s forming islands
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    area[index] = dfs(grid, i, j, index);
                    maxArea = max(maxArea, area[index]);
                    index++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {
                    set<int> visitedColors;
                    //calculate area of 1s formed after this 0 to 1 inversion
                    int total = 1; //total = 1 for the newly tranformed 0
                    for(auto p : neighbour(n, i, j))
                    {
                        int currColor = grid[p.first][p.second];
                        if(currColor > 1 && visitedColors.count(currColor) == 0)
                        {
                            visitedColors.insert(currColor);
                            total+= area[currColor];
                        }
                    }
                    maxArea = max(maxArea, total);
                }
            }
        }
        return maxArea;
    }
};