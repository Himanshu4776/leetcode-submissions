class Solution {
public:
    string removeOuterParentheses(string s) {
//         stack<int>sr;
//         string res = "";
//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i] == '(')
//             {
//                 if(sr.size() > 0)
//                     res += s[i];
                
//                 sr.push(s[i]);
//             }
//             else if(s[i] == ')')
//             {
//                 if(sr.size() > 1)
//                     res += s[i];
                
//                 sr.pop();
//             }
//         }
//         return res;
        int sr = 0;
        string res = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                if(sr > 0)
                    res += s[i];
                
                sr++;
            }
            else if(s[i] == ')')
            {
                if(sr > 1)
                    res += s[i];
                
                sr--;
            }
        }
        return res;
    }
};