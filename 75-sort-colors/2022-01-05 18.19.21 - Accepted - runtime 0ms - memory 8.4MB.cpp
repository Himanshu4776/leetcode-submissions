class Solution {
public:
    void sortColors(vector<int>& nums) {
        // No use of sort function so let's code it via bubblw sort.
        int n = nums.size();
        int zeros = 0,ones=0,twos=0;
        for(int j=0;j<n;j++)
        {
            if(nums[j] == 0) zeros += 1;
            if(nums[j] == 1) ones += 1;
            if(nums[j] == 2) twos += 1;
        }
        // cout<<zeros<<" "<<ones<<" "<<twos<<endl;
        for(int j=0;j<n;j++)
        {
            if(zeros != 0)
            {
                nums[j] = 0;
                zeros--;
            }
            else if(ones != 0)
            {
                nums[j] = 1;
                ones--;
            }
            else
            {
                nums[j] = 2;
            }
        }
    }
};