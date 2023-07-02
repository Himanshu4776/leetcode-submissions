class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>temp;
        unordered_set<int>s1,s2;
        vector<vector<int>>ans;
        unordered_set<int> :: iterator itr;
        
        for(int i=0;i<n;i++) s1.insert(nums1[i]);
        for(int i=0;i<m;i++) s2.insert(nums2[i]);
        
        for (itr = s1.begin(); itr != s1.end(); itr++)
        {
            if(s2.find(*itr) == s2.end()) temp.push_back(*itr);
        }
        ans.push_back(temp);
        temp.clear();
        
        for (itr = s2.begin(); itr != s2.end(); itr++)
        {
            if(s1.find(*itr) == s1.end()) temp.push_back(*itr);
        }
        ans.push_back(temp);
        return ans;
    }
};