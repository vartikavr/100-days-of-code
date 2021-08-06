//O(n) time, O(n) space

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> row;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                Node *curr = q.front();
                q.pop();
                int n = curr->children.size();
                for(int childNo=0;childNo<n;childNo++)
                {
                    if(curr->children[childNo] != NULL)
                        q.push(curr->children[childNo]);
                }
                row.push_back(curr->val);
            }
            res.push_back(row);
        }
        return res;
    }
};