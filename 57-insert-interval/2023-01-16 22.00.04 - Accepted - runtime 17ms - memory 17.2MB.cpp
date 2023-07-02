class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int new_r = newInterval[1];
        int new_l = newInterval[0];
        auto it = upper_bound(intervals.begin(), intervals.end(), newInterval, [&] (const vector<int>& v1, const vector<int>& v2) {
            return v2[1] >= v1[0];
        });

        int left_index = distance(intervals.begin(), it);
        
        // find the index of first interval that has left > new_r
        it = lower_bound(intervals.begin(), intervals.end(), newInterval, [&] (const vector<int>& v1, const vector<int>& v2) {
            return v1[0] <= v2[1];
        });

        int right_index = distance(intervals.begin(), it) - 1;
        // [left_idx : right_idx] should be merged
        if (right_index >= 0 && left_index < intervals.size() && left_index <= right_index) {
            new_l = min(new_l, intervals[left_index][0]);
            new_r = max(new_r, intervals[right_index][1]);
            it = intervals.erase(intervals.begin() + left_index, intervals.begin() + right_index + 1);
            intervals.insert(it, {new_l, new_r});
        }
        else if (right_index < 0) {
            intervals.insert(intervals.begin(), newInterval);
        }
        else if (left_index >= intervals.size()) {
            intervals.push_back(newInterval);
        }
        // a standalone interval that does not touch any other, so insert it at the last vector
        else {
            intervals.insert(intervals.begin() + left_index, newInterval);
        }
        return intervals;
    }
};