class Solution {
public:
    bool isPossible(vector<int>& nums) {
        bool ans = false;
        int n = nums.size();
        unordered_map<int,int>fm;// map for counting th frequency
        unordered_map<int,int>hm;
        // map for checking which number is required next and how many times it si required.
        
        // Each time we check if there's frequency of any element exist, 
        // we check can it be include with any sequence in hm.
        // If not then create an another sequence. we will also take i+1, i+2 in account for seq.
        // and remove their freq in fm. if not found either i+1,i+2 return false;
        // if whole array is traversed the return true else false;
        for(int i=0;i<n;i++) fm[nums[i]]++;
        
        // here we are adding and deleting values of arr[i] not arr[i-1] or arr[i+1].
        for(auto x:nums)
        {
            if(fm[x] == 0) continue;
            
            // check in hm for exisrting seq.
            if(hm[x-1] != 0) {
                fm[x]--;
                hm[x-1]--;
                // new requirement added in HM.
                hm[x]++;
            }
            else {
                // create new sequence.
                fm[x]--;
                if(fm[x+1] == 0 || fm[x+2] == 0) return false;
                fm[x+1]--;
                fm[x+2]--;
                // craeatd new wanting in HM
                hm[x+2]++;
            }
        }
        return true;
    }
};