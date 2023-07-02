class Solution {
public:
    const vector<pair<int, string>> converter = {{1000, "M"},
                                            {900, "CM"},
                                            {500, "D"},
                                            {400, "CD"},
                                            {100, "C"},
                                            {90, "XC"},
                                            {50, "L"},
                                            {40, "XL"},
                                            {10, "X"},
                                            {9, "IX"},
                                            {5, "V"},
                                            {4, "IV"},
                                            {1, "I"}};
    string intToRoman(int n) {
        string s;
        auto it = converter.begin();
        while(n > 0 && it != converter.end()) {
            if(n >= it->first) {
                s += it->second;
                n -= it->first;
            }
            else {
                ++it;
            }
        }
        return s;
    }
};