class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int curr = 0, n = gain.size();
        for(int i=0;i<n;i++) {
            curr += gain[i];
            if(curr > ans) {
                ans = curr;
            }
        }

        return ans;
    }
};