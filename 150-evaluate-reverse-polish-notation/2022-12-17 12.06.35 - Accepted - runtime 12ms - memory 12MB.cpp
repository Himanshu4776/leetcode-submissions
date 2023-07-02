class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int>st;
        for(auto d:tokens)
        {
            if(d.size() == 1 && !isdigit(d[0])) {
                long long int first = st.top();
                st.pop();
                long long int second = st.top();
                st.pop();
                if(d[0] == '+') st.push(first+second);
                if(d[0] == '-') st.push(second-first);
                if(d[0] == '*') st.push(first*second);
                if(d[0] == '/') st.push(second/first);
            }
            else st.push(stoi(d));
        }
        return st.top();
    }
};