class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>m;
        int res = 0;
        for(int i=0;i<tasks.size();i++) m[tasks[i]]++;
        for(auto it:m)
        {
            int val = it.second;
            if(val == 1) return -1;
            else if(val%3 == 0) res += val/3;
            else
            {
                res += val/3;
                res += 1;
            }
        }
        return res;
    }
};