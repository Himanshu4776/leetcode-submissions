class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int diff,baseDiff = arr[1] - arr[0];
        for(int i=2;i<n;i++) {
            diff = arr[i] - arr[i-1];

            if(diff != baseDiff) {
                return false;
            }
        }

        return true;
    }
};