class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long val = num/3;
        vector<long long> ans;
        if((val + val-1 + val+1) == num) {
            ans.push_back(val-1);
            ans.push_back(val);
            ans.push_back(val+1);
        }

        return ans;
    }
};