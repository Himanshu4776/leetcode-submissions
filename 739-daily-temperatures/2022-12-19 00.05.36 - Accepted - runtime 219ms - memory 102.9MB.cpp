class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s; // indices of temperature decreasing days
        vector<int> res(t.size());
        for (int i = 0; i < t.size(); s.push(i++))
            while (!s.empty() && t[s.top()] < t[i]) res[s.top()] = i-s.top(), s.pop();

        return res;
    }
};