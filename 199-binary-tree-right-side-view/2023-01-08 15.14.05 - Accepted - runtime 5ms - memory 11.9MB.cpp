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
// DFS Solution:
    // void solve(TreeNode* root, vector<int>&ans, int len) {
    //     if(!root) return;
    //     if(ans.size() == len) {
    //         ans.push_back(root->val);
    //     }

    //     solve(root->right,ans,len+1);
    //     solve(root->left,ans,len+1);
    // }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        // solve(root,ans, 0);
        // return ans;
        
        // BFS Solution:
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            TreeNode* temp;
            for(int i=0;i<sz;i++) {
                temp=q.front();
                if(i == sz-1) ans.push_back(temp->val);
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            // ans.push_back(temp->val);
        }
        return ans;
    }
};