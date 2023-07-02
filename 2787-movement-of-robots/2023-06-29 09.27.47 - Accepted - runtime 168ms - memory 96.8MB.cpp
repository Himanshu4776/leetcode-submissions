class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        long long mod=1e9+7;
        long long n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R')
                nums[i]+=d;
            else
                nums[i]-=d;
        }
        vector<long long > pref(n,0);
        sort(nums.begin(),nums.end());
        pref[0]=nums[0];
        pref[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
            pref[i]=pref[i-1]+nums[i];
        long long ans=0;
        long long cnt=1;
        for(int i=1;i<n;i++)
        {
            ans=(ans+(cnt*nums[i])-pref[i-1]);
            ans=ans%mod;
            cnt++;
        } 
        return ans%mod;
    }
};