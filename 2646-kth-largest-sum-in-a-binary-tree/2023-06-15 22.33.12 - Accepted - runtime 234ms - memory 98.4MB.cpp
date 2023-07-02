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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long>pq;
        int levels = 0;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            long long sum = 0;
            levels++;
            
            for(int i=0;i<size;i++) {
                TreeNode* temp = q.front();
                q.pop();

                sum += temp->val;

                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
            pq.push(sum);
        }
        for(int i=0;i<k-1;i++) {
            pq.pop();
        }
        if(levels < k) return -1;

        return pq.top();
    }
};