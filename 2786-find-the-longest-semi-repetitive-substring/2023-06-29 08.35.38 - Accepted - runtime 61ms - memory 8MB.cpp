class Solution {
public:
    int ans = 0;
    void printSubstrings(string str) {
        // First loop for starting index
        for (int i = 0; i < str.length(); i++) {
            string subStr;
            // Second loop is generating sub-string
            for (int j = i; j < str.length(); j++) {
                subStr += str[j];
                int rep = 0;
                for(int d=1;d<subStr.size();d++)
                {
                    if(subStr[d-1] == subStr[d]) rep++;
                    else if(rep > 1 && subStr[d] == subStr[d-1]) {
                        rep++;
                        break;
                    }
                }
                int len = subStr.size();
                if(rep <= 1) {
                    ans = max(ans, len);
                }
            }
        }
    }

    int longestSemiRepetitiveSubstring(string s) {
        printSubstrings(s);
        return ans;
    }
};