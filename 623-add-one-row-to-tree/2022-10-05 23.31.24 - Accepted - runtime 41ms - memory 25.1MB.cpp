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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode* newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        
        while(!q.empty()) 
        {
            int n = q.size(); 
            count++;
            while(n--)
            {
                TreeNode* curr = q.front();
                q.pop(); 
                if(count != depth - 1) 
                {
                    if(curr -> left) q.push(curr -> left);
                    if(curr -> right) q.push(curr -> right);
                }
                else // else we reach our required level
                {
                    TreeNode* newNode = new TreeNode(val);
                    // first put left of curr to newNode
                    newNode -> left = curr -> left;
                    // now curr of left becomes newNode
                    curr -> left = newNode;
                    
                    // make a new node to add
                    TreeNode* newNode2 = new TreeNode(val);
                    // first put right of curr to newNode
                    newNode2 -> right = curr -> right;
                     // now curr of right becomes newNode
                    curr -> right = newNode2;
                }
            }
        }
        return root;
    }
};