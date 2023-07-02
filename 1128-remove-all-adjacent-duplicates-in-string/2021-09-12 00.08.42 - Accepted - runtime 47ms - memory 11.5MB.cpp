class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string res = "";
        // for(int i=0;i<s.size();i++)
        // {
        //     st.push(s[i]);
        // }
        // // we got the values in our stack
        // while(!st.empty())
        // {
        //     if(st.top() != res[res.size()-1])
        //     {
        //         res += st.top();
        //         st.pop();
        //     }
        //     else
        //     {
        //         res.erase(res.begin() + res.size()-1);
        //         st.pop();
        //     }
        // }
        
        // another approach:
        for(auto c:s)
        {
            if(st.empty() || c != st.top())
                st.push(c);
            else
                st.pop();
        }
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};