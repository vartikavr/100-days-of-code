//O(n) time, O(n) space

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
    void countGood(TreeNode* root, int &count, int maxVal)
    {
        if(root==NULL)
            return;
        if(root->val >= maxVal){
            maxVal = root->val;
            count++;
        }
        countGood(root->left, count, maxVal);
        countGood(root->right, count, maxVal);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int count=0, maxVal = root->val;
        countGood(root, count, maxVal);
        return count;
    }
};