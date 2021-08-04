//O(n) time

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void calPath(TreeNode *root, vector<int> path, vector<vector<int>> &res, int target)
    {
        if(root == NULL)
            return;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == target)
        {
            res.push_back(path);
            return;
        }
        calPath(root->left, path, res, target - root->val);
        calPath(root->right, path, res, target - root->val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> res;
        calPath(root, path, res, targetSum);
        return res;
    }
};