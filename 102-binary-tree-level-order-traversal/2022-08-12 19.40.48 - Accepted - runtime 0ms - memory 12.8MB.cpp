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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>sol;
        if(root == NULL) return sol;
        queue<TreeNode*>q;
        q.push(root);
        // pushed the root in queue to keep track of visted nodes.
        while(!q.empty())
        {
            int size = q.size();
            vector<int>level;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                // Now look for its left and right values to push into queue.
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                     q.push(temp->right);
                // push this level values into level vector for this level values
                level.push_back(temp->val);
            }
            // Now put the level values vector into sol 2-d vector o return;
            sol.push_back(level);
        }
        return sol;
    }
};