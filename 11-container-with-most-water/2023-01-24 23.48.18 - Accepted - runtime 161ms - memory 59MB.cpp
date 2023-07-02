class Solution {
public:
    int maxArea(vector<int>& height) {
        long long int ans = 0;
        int i=0,j=height.size()-1;
        while(i<j) {
            long long int minval = min(height[i],height[j]);
            long long int val = minval*(j-i);
            ans = max(ans, val);

            if(height[i] < height[j]) i++;
            else j--;
        }
        return ans;
    }
};