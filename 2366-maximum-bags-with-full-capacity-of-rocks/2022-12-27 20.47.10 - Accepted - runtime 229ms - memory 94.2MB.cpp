class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        priority_queue<long long int, vector<long long int>, greater<long long int> > diff;
        for(int i=0;i<n;i++) {
            diff.push(capacity[i] - rocks[i]);
        }
        // Now check for smaller difference values first and count them.
        long long int count = 0;
        while(additionalRocks != 0 && !diff.empty()) {
            if(diff.top() == 0) count++;
            else if(diff.top() <= additionalRocks) {
                count++;
                additionalRocks -= diff.top();
            }
            else {
                additionalRocks = 0;
            }
            diff.pop();
        }
        return count;
    }
};