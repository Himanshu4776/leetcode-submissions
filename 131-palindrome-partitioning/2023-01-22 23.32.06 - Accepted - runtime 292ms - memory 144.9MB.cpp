class Solution {
public:
    bool ispalindrome(string str, int int_point, int fin_point) {
        int i = int_point, j = fin_point;
        while(i<j) {
            if(str[i] == str[j]) {
                i++;
                j--;
            }
            else return 0;
        }
        return 1;
    }
    void f(int i, string s, vector<string>path, vector<vector<string>>&ans) {
        if(i == s.size()) {
            ans.push_back(path);
            return;
        }
        for(int point=i; point<s.size(); point++) {
            if(ispalindrome(s, i, point)) {
                path.push_back(s.substr(i, point-i+1));
                f(point+1, s, path, ans);
                // backtrack and remove the current substring from path vector
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        f(0,s,path,ans);
        return ans;
    }
};