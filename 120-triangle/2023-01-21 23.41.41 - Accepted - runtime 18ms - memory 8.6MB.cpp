class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
	for(int level = 1; level < size(triangle); level++) {
		for(int i = 0; i <= level; i++) {
            // triangle[level].size() == level + 1 (level starts from 0)
			// for the current level: 
			triangle[level][i] += min(triangle[level - 1][min(i, (int)size(triangle[level - 1]) - 1)],
                triangle[level - 1][max(i - 1, 0)]);
            // or the previous level and index-1 
        }
    }
    // finally return the last element of the bottom level
	return *min_element(begin(triangle.back()), end(triangle.back())); 
    }
};