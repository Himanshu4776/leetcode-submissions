class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += mat[i][i];
        }
        for(int i=0;i<n;i++) {
            sum += mat[n-i-1][i];
        }
        if(n%2 != 0) sum -= mat[n/2][m/2];
        return sum;
    }
};