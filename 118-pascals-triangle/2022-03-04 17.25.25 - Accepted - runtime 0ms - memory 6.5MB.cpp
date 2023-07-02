class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res(numRows);
        
        for(int i=0;i<numRows;i++) {
            
            vector<int>temp(i+1,0);
            if(i == 0) temp[0] = 1;
            if(i == 1) {
                temp[0] = 1;
                temp[1] = 1;
            }
            else {
                temp[0] = 1;
                temp[i] = 1;
                for(int j = 1;j<i;j++) {
                    temp[j] = res[i-1][j-1] + res[i-1][j];
                }
            }
            res[i] = temp;
        }
        return res;
    }
};