class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        
        // Prefix sum for each row
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                matrix[i][j] += matrix[i][j-1] ;   
            }
        }
        
        int answer = 0;
        for(int start=0; start <n; start++){
            for(int end= start; end<n; end++){
                
                map<int,int> hash;
                
                hash[0] = 1;// default for edge case
                
                int sum = 0;
                for(int line =0; line < m; line++){
                    if(start!=0){
                        sum += matrix[line][end] - matrix[line][start-1] ;
                    }
                    else{
                       sum += matrix[line][end];
                    }
                    
                    // 5 -> 1
                    // sum = 5
                    // Target =10 
                    
                    // find all area having sum  [sum - target]
                    if(hash.find(sum - target) != hash.end())
                        answer += hash [sum - target];
                    
                    hash[sum]++;
                }
                
            }
        }
        
        return answer;
    }
};