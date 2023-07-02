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
    void dfs(TreeNode* node, vector<int> &arr)
    {
        if(node == NULL)
            return;
        dfs(node->left, arr);
        arr.push_back(node->val);
        dfs(node->right, arr);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        vector<int>arr;
        dfs(root,arr);
        int n = arr.size();
        int i=0,j=n-1;
        while(i<j)
        {
            int mid = (arr[i]+arr[j]);
            if(mid == k)
                return true;
            else if(mid > k)
                j--;
            else
                i++;
            
        }
        return false;
    }
};