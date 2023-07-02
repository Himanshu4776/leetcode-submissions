class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>st;
        int res = 0;
        for(auto c:logs)
        {
            if(c[0] != '.')
            {
                st.push(c);
            }
            else if(c == "../" && !st.empty())
            {
                st.pop();
            }
            else
            {
                continue;
            }
        }
        // now got all the inputs
        while(!st.empty())
        {
            res++;
            st.pop();
        }
        return res;
    }
};