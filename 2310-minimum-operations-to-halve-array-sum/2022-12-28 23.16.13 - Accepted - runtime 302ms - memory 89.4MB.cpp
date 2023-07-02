class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size(),count = 0;
        priority_queue<double>pq;
        double sum = 0,curr_sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            pq.push(nums[i]);
        }
        curr_sum = sum;
        while(curr_sum > (sum/2)) {
            count++;
            double t = pq.top();
            pq.pop();
            pq.push(t/2);
            curr_sum -= t/2;
        }
        return count;
    }
};