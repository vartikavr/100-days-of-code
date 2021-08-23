//O(nh) time, O(h) space

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
    bool search(TreeNode* root, TreeNode* curr, int target)
    {
        if(root==NULL)
            return false;
        if(curr!=root && root->val==target)
            return true;
        if(root->val > target)
            return search(root->left, curr, target);
        return search(root->right, curr, target);
    }
    bool dfs(TreeNode* root, TreeNode* curr, int k)
    {
        if(curr==NULL)
            return false;
        return search(root, curr, k-(curr->val)) || dfs(root, curr->left, k) || dfs(root, curr->right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root, k);
    }
};