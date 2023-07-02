class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res = {-1,-1};
        if(nums.size()==0)
            return res;
        // if(nums.size() == 1)
        //     return {0,0};
        int frval = search(nums,target,true);
        int endval = search(nums,target,false);
        return {frval,endval};
    }
    int search(vector<int>&nums,int target,bool front)
    {
        int start = 0;
        int end = nums.size() -1;
        int ans = -1;
        while(start<= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] > target)
            {
                end = mid - 1;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                ans = mid;
                if(front)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid+1;
                }
            }
        }
        return ans;
    }
};