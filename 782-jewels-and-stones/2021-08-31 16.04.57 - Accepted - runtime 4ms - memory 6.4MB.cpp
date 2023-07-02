class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        unordered_map<char,int>m;
        for(int i=0;i<stones.length();i++)
        {
            m[stones[i]]++;
        }
        // now have all unique stones.
        for(char c:jewels)
        {
            if(m.count(c) !=0)
                ans += m[c];
        }
        return ans;
    }
};