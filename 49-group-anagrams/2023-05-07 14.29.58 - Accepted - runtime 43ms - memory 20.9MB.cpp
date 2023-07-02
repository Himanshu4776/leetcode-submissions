class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 1)
            return {{strs[0]}};
        
        vector<vector<string>>ans;
        map<string, vector<string>>m;
        for(int i=0;i<strs.size();i++)
        {
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());// Now it is equal to other strings
            m[strs[i]].push_back(s);// sorted string strs[i] will act as a key
            // and s will be stored in the vector allocate to that key.
        }
        // Traversal complete now put vectors of strings into answer
        for(auto it:m) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};