class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int closest, min = INT_MAX;
        for(int i=0; i<n-2; ++i)
        {
            if(i==0 || nums[i]!=nums[i-1]){
                int low = i+1;
                int high = n-1;
                while(low<high)
                {
                    int sum = nums[i] + nums[low] + nums[high];
                    if(sum == target) return sum;
                    else if(sum > target) high--;
                    else low++;
                    if(abs(sum-target)<min)
                    {
                        closest = sum;
                        min = abs(sum-target);
                    }
                }
            }
        }
        return closest;
    }
};