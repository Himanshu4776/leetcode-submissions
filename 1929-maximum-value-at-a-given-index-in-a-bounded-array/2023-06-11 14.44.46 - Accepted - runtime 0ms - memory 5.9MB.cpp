class Solution {
public:
    long calcArraySum(int index, int value, int n) {
        // calculate values on left of index
        long count = 0;
        // if valued is in left side of index
        if(value > index) {
            count += (long)(value + value - index)*(index+1)/2;
        } else {
            count += (long)(value + 1) * value / 2 + index - value + 1;
        }
        // if value is in right side of index
        if (value >= n - index) {
            count += (long)(value + value - n + 1 + index) * (n - index) / 2;
        } else {
            count += (long)(value + 1) * value / 2 + n - index - value;
        }
        return count - value;
    }
    int maxValue(int n, int index, int maxSum) {
        int low = 1, high = maxSum;
        while(low < high) {
            int mid = low + (high-low)/2 + 1;

            if(calcArraySum(index, mid, n) <= maxSum) {
                low = mid;
            }
            else {
                high = mid-1;
            }
        }

        return low;
    }
};