class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Using heap:
        int n = matrix.size();
        int m = matrix[0].size();
        
        // priority_queue<int, vector<int>, greater<int> > pq;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         pq.push(matrix[i][j]);
        //     }
        // }
        // int ans = 0;
        // for(int i= 0; i<k;i++)
        // {
        //     ans = pq.top();
        //     pq.pop();
        // }
        // Using sorting:
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr.push_back(matrix[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};