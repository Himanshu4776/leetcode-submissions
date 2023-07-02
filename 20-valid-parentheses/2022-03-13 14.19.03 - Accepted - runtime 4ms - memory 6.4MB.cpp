class Solution {
public:
    bool isValid(string j) {
        stack<char>st;
        bool ans = true;
        int l=j.length();
        for (int i = 0; i < l; i++)
        {
            /* traverse the string and check for stack tp element */
            if (j[i]=='(' || j[i]=='{' || j[i]=='[')
            {	
                st.push(j[i]);
            }
            if (j[i]==')')
            {
                if (!st.empty() && st.top() == '(')
                {
                    ans = true;
                    st.pop();
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            if (j[i]=='}')
            {
                if (!st.empty() && st.top() == '{')
                {
                    ans = true;
                    st.pop();
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            if (j[i]==']')
            {
                if (!st.empty() && st.top() == '[')
                {
                    ans = true;
                    st.pop();
                }
                else
                {
                    ans = false;
                    break;
                }
            }
        }
        if (!st.empty())
            return false;

        return ans;
    }
};