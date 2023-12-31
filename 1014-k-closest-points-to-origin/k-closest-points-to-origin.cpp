class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        priority_queue<pair<int, pair<int,int>>>pq;

        for(int i = 0; i<points.size(); i++)
        {
            pair<int, int>p;
            p.first = points[i][0];
            p.second = points[i][1];
            int sq = ((points[i][0] *points[i][0]) +  (points[i][1]*points[i][1]));
            pair<int, pair<int, int>>ppp;
            ppp.first = sq;
            ppp.second = p;
            pq.push(ppp);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        while(pq.size()>0)
        {
            v.push_back(pq.top().second.first);
            v.push_back(pq.top().second.second);
            ans.push_back(v);
            v.clear();
            pq.pop();
        }
        return ans;
    }
};