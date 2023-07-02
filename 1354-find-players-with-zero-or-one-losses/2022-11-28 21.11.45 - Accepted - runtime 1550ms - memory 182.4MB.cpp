class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> lost;
        for (auto m : matches) {
            if (!lost.count(m[0])) lost[m[0]] = 0;
            lost[m[1]]++;
        }
        
        vector<int> zero, ones;
        for (auto[key,loses] : lost) {
            if (loses == 0) zero.push_back(key);
            if (loses == 1) ones.push_back(key);
        }
        
        return {zero,ones};
    }
};