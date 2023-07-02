class Solution {
public:
    string findDifferentBinaryString(vector<string>& v) {
        set<string>nums(v.begin(), v.end());
        int n = v.size();
        
        for(int i=0; i<17; i++){
            string str = bitset<16>(i).to_string();
            str = str.substr(str.size()-n, n);
            if(nums.find(str) == nums.end())
                return str;
        }
        return "";
    }
};