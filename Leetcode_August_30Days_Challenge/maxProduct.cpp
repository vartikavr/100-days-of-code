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
    long long totalSum=0, res=0;
    int mod= 1e9 + 7;
    void fullTreeSum(TreeNode* root)
    {
        if(root == NULL)
            return;
        totalSum+= root->val;
        fullTreeSum(root->left);
        fullTreeSum(root->right);
    }
    int splitSum(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        long long sum= root->val + splitSum(root->left) + splitSum(root->right);
        res= max(res, sum*(totalSum-sum));
        return sum;
    }
    int maxProduct(TreeNode* root) {
        fullTreeSum(root);
        splitSum(root);
        return res%mod;
    }
};