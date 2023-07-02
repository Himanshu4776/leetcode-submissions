class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size()-1;
        int i=0;
        while(i<matrix.size() && n >= 0)
        {
            if(target == matrix[i][n])
                return true;
            else if(target > matrix[i][n])
            {
                i++;
            }
            else
            {
                n--;
            }
        }
        return false;
    }
};