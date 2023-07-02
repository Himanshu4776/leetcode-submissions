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
    vector<vector<int>>ans;
    void solve(TreeNode* root,vector<int>path,int targetsum,vector<vector<int>>&ans) {
        if(!root) return;
        if(!root->left && !root->right && targetsum == root->val) {
            path.push_back(root->val);
            ans.push_back(path);
            return;
        }
        
        path.push_back(root->val);
        solve(root->left,path,targetsum-root->val,ans);
        solve(root->right,path,targetsum-root->val,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetsum) {
        vector<vector<int>>ans;
        vector<int>path;
        solve(root, path, targetsum, ans);
        return ans;
    }
};