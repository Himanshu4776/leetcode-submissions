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
int preindex = 0;
    TreeNode* ctree(vector<int>& in, vector<int>& pre, int is, int ie) {
        // in only one condition ie will be less than is
        // when we will fully traverse the whole both arrrays. In that case
        if(is > ie) return NULL;

        // the first index of preorder will always give the root of the tree
        TreeNode* root = new TreeNode(pre[preindex++]);
        
        // find the node of preorder and inorder intersection.
        int index;
        for (int i = is; i <= ie; ++i)
        {
            if(in[i] == root->val) {
                index = i;
                break;
            }
        }
        
        // left part of index will be the left subtree
        root->left = ctree(in,pre,is,index-1);
        
        // right part of index will be the right subtree
        root->right = ctree(in,pre,index+1,ie);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int is = 0, ie = preorder.size()-1;
        return ctree(inorder,preorder,is,ie);
    }
};