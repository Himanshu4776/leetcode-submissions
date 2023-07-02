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
    void solve(TreeNode* root, string s,vector<string>&ds)
    {
        if(root == NULL) ds.push_back(s);
        else{
            if(s.size() == 0){
                // s += (abs(root->val) + '0');
                s += to_string(root->val);
            }
            else {
                s += "->";
                // s += (abs(root->val) + '0');
                s += to_string(root->val);
            }
        }
        if(root->left == NULL && root->right == NULL) ds.push_back(s);
        
        if(root->left != NULL) solve(root->left,s,ds);
        if(root->right != NULL) solve(root->right,s,ds);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ds;
        if(!root) return ds;
        string s;
        solve(root,s,ds);
        return ds;
    }
};