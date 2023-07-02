class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0,n = nums1.size();
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m[nums1[i] + nums2[j]]++;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val = nums3[i] + nums4[j];
                val = val*-1;
                
                if(m[val] > 0) res += m[val];
            }
        }
        return res;
    }
};