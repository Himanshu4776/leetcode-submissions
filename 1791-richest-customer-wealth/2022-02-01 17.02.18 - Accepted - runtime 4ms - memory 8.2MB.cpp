class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxwealth = INT_MIN;
        int val = 0;
        for(auto it:accounts)
        {
            for(auto d:it)
            {
                val += d;
            }
            if(val > maxwealth)
                maxwealth = val;
            
            val = 0;
        }
        return maxwealth;
    }
};