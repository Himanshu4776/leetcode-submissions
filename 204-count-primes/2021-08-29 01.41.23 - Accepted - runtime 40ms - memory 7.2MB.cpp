class Solution {
public:
    int countPrimes(int n) {
        vector<bool>arr(n+1,false);
        int count = 0;
        for (int i = 2; i*i<n; ++i)
        {
            if (arr[i] == 0)
            {
                for (int d = i*i; d <= n; d+=i)
                {
                    arr[d] = 1;
                }
            }
        }
        for (int i = 2; i < n; ++i)
        {
            if (arr[i] == 0)
            {
                count++;
            }
        }
        return count;
    }
};