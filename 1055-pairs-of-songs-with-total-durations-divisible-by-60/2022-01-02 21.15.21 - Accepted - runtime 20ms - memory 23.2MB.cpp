class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0, count[60] = {0};
        for (int i = 0; i < time.size(); i ++){
            count[time[i] % 60] += 1;
        }
        for (int i = 1; i< 30; i ++){
            ans += count[i] * count[60 - i];
        }
        ans += count[0] * (count[0] - 1) / 2 + count[30] * (count[30] - 1) / 2;
        
        return ans;
    }
};