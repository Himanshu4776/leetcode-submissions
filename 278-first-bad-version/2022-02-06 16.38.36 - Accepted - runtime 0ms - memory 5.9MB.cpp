// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        long long int mid;
        while(start <= n)
        {
            mid = start + (n-start)/2;
            if(!isBadVersion(mid))
            {
                start = mid + 1;
            }
            else
                n = mid - 1;
        }
        return n+1;
    }
};