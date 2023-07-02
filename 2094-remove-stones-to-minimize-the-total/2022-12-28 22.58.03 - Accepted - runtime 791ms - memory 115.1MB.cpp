class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<double>pq;
        int n = piles.size();
        for(int i=0;i<n;i++) pq.push(piles[i]);
        while(k) {
            double t = pq.top();
            pq.pop();
            // cout<<ceil(t/2)<<" ";
            pq.push(ceil(t/2));
            k--;
        }
        long long int ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};