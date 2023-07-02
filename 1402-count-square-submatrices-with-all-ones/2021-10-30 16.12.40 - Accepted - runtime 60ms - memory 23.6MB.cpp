class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j] == 1)
                {
                    matrix[i][j] = 1 + min(matrix[i][j-1],min(matrix[i-1][j],matrix[i-1][j-1]));
                }
            }
        }
        int sum = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum += matrix[i][j];
            }
        }
        return sum;
    }
};