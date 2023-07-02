class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>pref(n,0);
        vector<int>suf(n,0);
        int maxval = INT_MIN;
        for(int i=0;i<n;i++) {
            maxval = max(maxval,height[i]);
            pref[i] = maxval;
        }
        maxval = INT_MIN;
        for(int i=n-1;i>=0;i--) {
            maxval = max(maxval,height[i]);
            suf[i] = maxval;
        }
        // Now we have got the prefix array and suffix array
        // Now we can get the min(pref[i],suf[i]) - arr[i]
        // this will give us the amount of water stored at that point
        vector<int>arr(n,0);
        for(int i=0;i<n;i++) {
            arr[i] = (min(pref[i],suf[i]) - height[i]);
        }
        int count = 0;
        for(int i=0;i<n;i++) count += arr[i];
        
        return count;
        // This is not optimized. lets optimize this using stack
    }
};