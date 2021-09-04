//O(n) time, O(n) space
//reference -> https://leetcode.com/problems/sum-of-distances-in-tree/discuss/130583/C%2B%2BJavaPython-Pre-order-and-Post-order-DFS-O(N)

class Solution {
public:
    void dfsPost(int root, int prev, vector<int> &count, vector<int> &subsetSum, vector<unordered_set<int>> &tree)
    {
        for(auto i : tree[root])
        {
            if(i == prev)
                continue;
            dfsPost(i, root, count, subsetSum, tree);
            count[root]+= count[i];
            subsetSum[root]+= subsetSum[i] + count[i];
        }
    }
    void dfsPre(int root, int prev, vector<int> &count, vector<int> &subsetSum, vector<unordered_set<int>> &tree)
    {
        for(auto i:tree[root])
        {
            if(i == prev)
                continue;
            subsetSum[i] = subsetSum[root] - count[i] + (count.size() - count[i]);
            dfsPre(i, root, count, subsetSum, tree);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> tree(n);
        vector<int> count(n, 1);
        vector<int> subsetSum(n, 0);
        for(int i=0;i<edges.size();i++)
        {
            tree[edges[i][0]].insert(edges[i][1]);
            tree[edges[i][1]].insert(edges[i][0]);
        }
        dfsPost(0, -1, count, subsetSum, tree);
        dfsPre(0, -1, count, subsetSum, tree);
        return subsetSum;
    }
};