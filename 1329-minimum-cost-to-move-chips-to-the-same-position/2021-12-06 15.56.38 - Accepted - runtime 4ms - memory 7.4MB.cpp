class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0;
        int odd = 0;
        int n = position.size();
        for(int i=0;i<n;i++)
        {
            if(position[i]%2 == 0)
            {
                // even
                even++;
            }
            else
                odd++;
        }
        return min(odd,even);
    }
};