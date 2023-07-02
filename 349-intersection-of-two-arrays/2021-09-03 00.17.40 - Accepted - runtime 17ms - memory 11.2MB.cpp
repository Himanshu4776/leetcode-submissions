class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>counter;
        for(int i=0;i<nums1.size();i++)
        {
            counter[nums1[i]]++;
        }
        
        map<int,int>ansmap;
        for(int i=0;i<nums2.size();i++)
        {
            if(counter[nums2[i]]>0)// check for matching values
            {
                ansmap[nums2[i]] = 1;// set matched values to 1
            }
        }
        vector<int>ans;
        for(int i=0;i<nums2.size();i++)
        {
            if(ansmap[nums2[i]] ==1)
                ans.push_back(nums2[i]);
            ansmap[nums2[i]] = 0;
        }
        return ans;
    }
};