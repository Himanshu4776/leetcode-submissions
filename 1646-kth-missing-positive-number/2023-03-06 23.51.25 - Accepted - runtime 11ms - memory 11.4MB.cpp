class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 0, n = arr.size();
        unordered_map<int,int>m;

        for(int i=0;i<n;i++) m[arr[i]]++;
        
        for(int i = 1;i <= arr[n-1]; i++) {
            if(m[i] == 0) k-=1;
            if(k == 0) return i;
        }
        if(k != 0) ans = arr[n-1] + k;
        
        return ans;
    }
};