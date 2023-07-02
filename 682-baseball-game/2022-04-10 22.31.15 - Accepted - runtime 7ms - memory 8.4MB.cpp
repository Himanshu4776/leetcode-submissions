class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        stack<int>st;
        for(auto c:ops)
        {
            if(c == "+")
            {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.push(temp1);
                st.push(temp1 + temp2);
            }
            else if(c == "D")
            {
                int temp = 2*st.top();
                st.push(temp);
            }
            else if(c == "C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(c)); //stoi() to convert string into integer 
            }
        }
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};