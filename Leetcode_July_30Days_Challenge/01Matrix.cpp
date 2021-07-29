//O(row*col) time -> BFS

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m, INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
        int move[4][2] = {{-1,0}, {0,1}, {1,0}, {0, -1}};
        while(!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int row = curr.first + move[k][0], col = curr.second + move[k][1];
                if(row>=0 && col>=0 && row<n && col<m)
                {
                    if(dist[row][col] > dist[curr.first][curr.second] + 1)
                    {
                        dist[row][col] = dist[curr.first][curr.second] + 1;
                        q.push({row, col});
                    }
                }
            }
        }
        return dist;
    }
};