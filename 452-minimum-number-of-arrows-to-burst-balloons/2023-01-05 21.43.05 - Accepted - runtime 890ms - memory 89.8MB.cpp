class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans = 1, n = points.size();
        int lastPoint = points[0][1];
        for(int i=0;i<n;i++) {
            if(lastPoint < points[i][0]) {
                ans++;
                lastPoint = points[i][1];
            }
            else {
                lastPoint = min(lastPoint,points[i][1]);
            }
        }
        return ans;
    }
};