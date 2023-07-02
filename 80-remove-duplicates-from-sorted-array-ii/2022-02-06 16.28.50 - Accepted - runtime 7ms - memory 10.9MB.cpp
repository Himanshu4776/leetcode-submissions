class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>m;
        int n = nums.size(),k = 1,count=1;// first element is always included
        for(int i=1;i<n;i++)
        {
            if(nums[i] == nums[i-1])
                count++;
            else count=1;// new elemnt found reset it to 1;
            
            // if count is less than 3 then set the values else
            // it is higher so continue;
            if(count <= 2)
                nums[k++] = nums[i];
            else continue;
        }
        return k;
    }
};