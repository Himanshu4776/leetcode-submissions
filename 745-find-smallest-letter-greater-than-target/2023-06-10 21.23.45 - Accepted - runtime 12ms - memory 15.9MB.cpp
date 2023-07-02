class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char target) {
        int low = 0;
        int high = l.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(l[mid] > target)
                 high = mid-1;
            else
            {
                low = mid + 1;
            }
        }
        
        return l[low%l.size()];
    }
};