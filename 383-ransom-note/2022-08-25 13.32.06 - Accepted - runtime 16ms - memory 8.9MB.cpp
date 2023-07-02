class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = magazine.size(), m = ransomNote.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[magazine[i]]++;
        }
        for(int i=0;i<m;i++)
        {
            if(mp[ransomNote[i]] > 0) mp[ransomNote[i]]--;
            else return false;
        }
        return true;
    }
};