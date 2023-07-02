class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i =0;
        int length = numbers.size() - 1;
        while (i<length)
        {
            if (numbers[i] + numbers[length] == target)
            {
                return {i+1, length+1};
            }
            else if (numbers[i] + numbers[length]> target)
            {
                length--;
            }
            else 
            {
                i++;
            }
        }
        return {};
    }
};