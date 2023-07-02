class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>mp;
        int n=text.length();
        for(char i:text)
        {
            mp[i] += 1;
        }
        int ans = min(mp['n'],min(mp['o']/2,min(mp['l']/2,min(mp['b'],mp['a']))));
        return ans;
    }
};