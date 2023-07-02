class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
       long long int i,j,l=0,r=INT_MAX,res=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            j=0;
            for(i=0;i<heaters.size();i++)
            {
                while(j<houses.size()&&abs(houses[j]-heaters[i])<=mid)
                {
                    j++;
                }
            }
            if(j==houses.size())
            {
                res=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return res;
    }
};