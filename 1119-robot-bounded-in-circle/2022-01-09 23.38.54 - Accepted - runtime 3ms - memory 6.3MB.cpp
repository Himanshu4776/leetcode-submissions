class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dir = {{0,1}, {-1, 0}, {0, -1}, {1,0}};
        int point = 0;
        int x = 0;
        int y = 0;
       
        for(int s = 0; s < instructions.size(); s++){
            if(instructions[s] == 'L'){
                point = (point + 1) % 4;
            }
            else if(instructions[s] == 'R'){
                point = (point + 3) % 4;
            }
            else{
                x = x + dir[point][0];
                y = y + dir[point][1];
            }
        }
        return x == 0 && y == 0 || point != 0;
    }
};