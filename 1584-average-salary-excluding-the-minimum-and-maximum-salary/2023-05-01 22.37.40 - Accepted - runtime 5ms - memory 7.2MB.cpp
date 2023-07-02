class Solution {
public:
    double average(vector<int>& salary) {
        long long int minval = INT_MAX;
        long long int maxval = 0;
        long long int sum = 0, n = salary.size();
        for(int i=0;i<n;i++) {
            sum += salary[i];
            if(minval > salary[i]) {
                minval = salary[i];
            }
            if(maxval < salary[i]) {
                maxval = salary[i];
            }
        }
        sum = sum - minval - maxval;
        n -= 2;

        double ans = (double)sum/n;

        return ans;
    }
};