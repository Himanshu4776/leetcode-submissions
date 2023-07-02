class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            m[nums[i]]++;
        }

        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(auto it:m) {
            pq.push({it.second, it.first});
        }

        for(int i=0;i<k;i++) {
            pair<int,int> top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }

        return ans;
    }
};