class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        /*bool result;
        if(std::is_sorted(nums.begin(),nums.end()))
        {
            result = true;
        }
        else if(std::is_sorted(nums.begin(),nums.end(), greater<int>()))
        {
            result = true;
        }
        else
        {
            result = false;
        }
        return result;*/
        bool increase = true;
        bool decrease = true;
        for(int i = 0; i < A.size() - 1; i++) {
            if(A[i] > A[i+1]) increase = false;
            if(A[i] < A[i+1]) decrease = false;
            if(increase == false && decrease == false) return false;
        }
        return true;
    }
};