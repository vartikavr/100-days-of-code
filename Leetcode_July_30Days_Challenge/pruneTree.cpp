//O(n) time, O(h) space

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
    bool checkPrune(TreeNode *root)
    {
        if(root->left!=NULL){
            bool result = checkPrune(root->left);
            if(result == true){
                root->left =NULL;
            }
        }
        if(root->right!=NULL){
            bool result = checkPrune(root->right);
            if(result == true){
                root->right= NULL;
            }
        }
        if(root->left==NULL && root->right==NULL && root->val == 0)
            return true;
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool result = checkPrune(root);
        if(result)
            return NULL;
        return root;
    }
};