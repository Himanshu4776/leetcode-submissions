class Solution {
public:
    int binary(vector<int> m) {
        int l = 0;
        int h = m.size()-1;
        while(l <= h) {
            int mid = l + (h-l)/2;
            if(m[mid] == 0)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>ans;
        set<pair<int,int>>s;
        int n = mat.size();
        int m = mat[0].size();
        // This approach complexity : O(n^2)
        // for(int i=0;i<n;i++) {
        //     int count = 0;
        //     for(int j=0;j<m;j++)
        //     {
        //         if(mat[i][j] == 1) count++;
        //         else if(mat[i][j] == 0) break;
        //     }
        //     s.insert(make_pair(count,i));
        //     // Here the deciding factor is always the first value
        //     // so here it would be count of those 1 values.
        // }
        for(int i=0;i<n;i++) // Here the copmlexity for finding: O(logn)
        {
            int val = binary(mat[i]);
            s.insert(make_pair(val,i));
        }
        // Now if we had used priority queue here then we could have solved it in
        // O(logn) + O(logk).
        
        // Now let's take out elements as sets would have already made them sort
        for(auto it:s)
        {
            if( k == 0) break;
            ans.push_back(it.second);
            k--;
        }
        return ans;
    }
};