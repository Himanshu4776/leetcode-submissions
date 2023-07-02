class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0;
        int total = row*col;
        
        //index initialisation
        int startRow = 0;  // starting row
        int startCol = 0;  // starting column
        int endRow = row -1;  // ending row
        int endCol = col-1;   // ending column

        while(count < total){

            //printing starting row
            for(int index = startCol; count < total && index <= endCol; index++){
               ans.push_back(matrix[startRow][index]);
               count++;
            }
            startRow++;

            //printing ending column
            for(int index = startRow; count < total && index <= endRow; index++){
               ans.push_back(matrix[index][endCol]);
               count++;
            }
            endCol--;

            //printing ending row
            for(int index = endCol; count < total && index >= startCol; index--){
               ans.push_back(matrix[endRow][index]);
               count++;
            }
            endRow--;

            //printing starting column
            for(int index = endRow; count < total && index >= startRow; index--){
               ans.push_back(matrix[index][startCol]);
               count++;
            }
            startCol++;
        }

        return ans;
    }
};