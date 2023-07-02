class Solution {
public:
    // Approach1: by backtracking:
    // long long int ans = 0;
    // void solve(int i, vector<int>&nums1,vector<int>& nums2, int k, vector<int>path, vector<int>sel) {
    //     if(i>= nums1.size() && sel.size() == k) {
    //         long long int val = 0, minval = INT_MAX;
    //         for(int j=0;j<k;j++) {
    //             val += path[j];
    //             if(minval > sel[j]) {
    //                 minval = sel[j];
    //             }
    //         }
    //         // cout<<val<< "  "<< minval<<endl;
    //         if(ans < val*minval) {
    //             ans = val*minval;
    //         }
    //         return;
    //     }
    //     if(i >= nums1.size()) return;

    //     path.push_back(nums1[i]);
    //     sel.push_back(nums2[i]);
    //     solve(i+1,nums1,nums2,k,path,sel);
    //     path.pop_back();
    //     sel.pop_back();
    //     solve(i+1,nums1,nums2,k,path,sel);
    // }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        if(n==1) {
            return nums1[0]*nums2[0];
        }
        // Backtrack approach:
        // vector<int>path;
        // vector<int>sel;
        // solve(0,nums1,nums2,k,path, sel);

        // sort + heap approach:
        vector<pair<int,int>> v;

        for(int i=0;i<nums1.size();i++) v.push_back({nums2[i],nums1[i]});

        sort(v.rbegin(),v.rend());

        long long ans = 0;
        long long currSum = 0;

        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i=0;i<k-1;i++){
            currSum += v[i].second;
            pq.push(v[i].second);
        }
        // now we have the windows size of k-1

        for(int i = k-1;i<nums1.size();i++){
            currSum += v[i].second;
            pq.push(v[i].second);
            ans = max(ans,currSum*v[i].first);
            // now we will add new elements to window and
            // check the sum as size of windows is now k

            currSum -= pq.top();
            pq.pop();
            // remove the prev element as window size needs to be k.
        }

        return ans;
    }
};