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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>sol;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            double sum = 0;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                // now lets go for left right values.
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
                sum += temp->val;
            }
            // here we will push the levels average value.
            sol.push_back(sum/size);
        }
        return sol;
    }
};