class Solution {
public:
    string getStr(int first, int last) {
        return first == last ? to_string(first) : to_string(first) + "->" + to_string(last);
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)
            return vector<string>();
        
        vector<string> res;
        int first = nums[0];
        for (int i=1; i<nums.size(); ++i)
        {
            if (nums[i-1]+1 != nums[i])
            {
                res.push_back(getStr(first, nums[i-1]));
                first = nums[i];
            }
        }
        res.push_back(getStr(first, nums.back()));
        return res;
    }
};