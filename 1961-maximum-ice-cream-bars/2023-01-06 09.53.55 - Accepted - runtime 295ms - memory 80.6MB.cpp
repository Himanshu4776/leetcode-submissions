class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Greedy using sort
        // int ans = 0;
        // int n = costs.size();
        // sort(costs.begin(),costs.end());
        // for(int i=0;i<n;i++) {
        //     if(coins >= costs[i]) {
        //         ans++;
        //         coins -= costs[i];
        //     }
        //     else break;
        // }
        // return ans;

        // Optimized to O(n) using map
        int result = 0;
        int max = *max_element(costs.begin(), costs.end());

        vector<int> countMap(max+1);
        for (auto& cost: costs) countMap[cost]++;

        for (int cost = 1; cost <= max; cost++) {
            if (countMap[cost] == 0) continue;
            if (cost > coins) break;

            // The terminology is either we take the minimum
            // either we take the count of map or 
            // no of coins we can take from the cost.
            int count = min(countMap[cost], coins / cost);
            coins -= count*cost;
            result += count;
        }
        return result;
    }
};