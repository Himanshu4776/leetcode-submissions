class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int lastval = n-1;
        for(int i=0;i<(n+1)/2;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                int temp = matrix[lastval - j][i];
                matrix[lastval - j][i] = matrix[lastval - i][n - j - 1];
                matrix[lastval - i][n - j - 1] = matrix[j][lastval -i];
                matrix[j][lastval - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};