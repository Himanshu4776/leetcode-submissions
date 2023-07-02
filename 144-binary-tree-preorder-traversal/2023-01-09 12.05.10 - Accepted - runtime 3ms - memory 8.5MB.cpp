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
    void pre(TreeNode* node, vector<int>&val)
    {
        if(node == NULL) return;
        val.push_back(node->val);
        if(node->left) pre(node->left,val);
        if(node->right) pre(node->right,val);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>val;
        pre(root,val);
        return val;
    }
};