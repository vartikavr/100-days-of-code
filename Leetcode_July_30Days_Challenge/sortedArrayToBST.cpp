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
    TreeNode* convert(vector<int> nums, int start, int end)
    {
        if(start > end)
            return NULL;
        int mid = (start+end)/2;
        TreeNode *curr = new TreeNode(nums[mid]);
        curr->left = convert(nums, start, mid-1);
        curr->right = convert(nums, mid+1, end);
        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        if(nums.size() == 1)
            return new TreeNode(nums[0]);
        return convert(nums, 0, nums.size()-1);   
    }
};