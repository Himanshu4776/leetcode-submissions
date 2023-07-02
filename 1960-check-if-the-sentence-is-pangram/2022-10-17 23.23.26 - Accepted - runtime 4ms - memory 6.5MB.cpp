class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>alphabets(26,0);
        int n = sentence.size();
        for(int i=0;i<n;i++)
        {
            alphabets[sentence[i] - 'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(alphabets[i] == 0) return false;
        }
        return true;
    }
};