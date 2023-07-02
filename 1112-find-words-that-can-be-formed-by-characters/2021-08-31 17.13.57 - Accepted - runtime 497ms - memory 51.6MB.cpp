class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>um;
        string ans="";
        for(char c:chars)
            um[c]++;
        // now all the chars characters are stored in map
        for(auto str:words)
        {
            bool flag = true;
            unordered_map<char,int>ucopy;
            for(char c:str)
            {
                ucopy[c]++;
            }
            for(char c:str)
            {
                if(ucopy[c] > um[c])
                    flag = false;
            }
            if(flag)
            {
                ans += str;
            }
        }
        return ans.length();
    }
};