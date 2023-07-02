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
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return (1+ max(lh,rh));
    }
    void fill(TreeNode* root,int row,int l,int r,vector<vector<string>>&ans) {
        if(root == NULL) return;
        
        int mid = (l+r)/2;
        ans[row][mid] = to_string(root->val);
        
        // Lets recurse now
        fill(root->left, row+1, l, mid-1,ans);
        fill(root->right, row+1, mid+1, r,ans);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int n = 0, m = 0;
        m = height(root);
        n = pow(2,m) - 1;
        vector<vector<string>>ans(m, vector<string>(n, ""));
        // fill(root,int row, int start, int end, array)
        fill(root,0,0,n-1,ans);
        return ans;
    }
    // One more Approach would be to use BFS:
    // push all te nodes values and their row and col in a queue of pair
    // the iterate the queue and psuh all the values into ans vector of string
};