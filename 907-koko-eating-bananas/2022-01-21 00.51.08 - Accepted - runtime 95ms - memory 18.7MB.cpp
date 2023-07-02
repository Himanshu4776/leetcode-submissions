class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {     
        // int speed = 1;
        // int n = piles.size();
        // while(true)
        // {
        //     int ans = 0;
        //     for(int i=0;i<n;i++)
        //     {
        //         ans += piles[i]/speed;
        //         if(piles[i]%speed) ans++;
        //     }
        //     // let's check if it is equal to h or not. if equal then lets return it.
        //     if(ans == h)
        //         return speed;
        //     else
        //         speed++;
        // }
        int n = piles.size();
        int maxval = *max_element(piles.begin(),piles.end());
        int i =1,j = maxval;
        while(i<j)
        {
            int mid = (i+j)/2;
            int ans = 0;
            for(auto p:piles)
            {
                ans += p/mid;
                if(p%mid) ans++;
            }
            // check if the ans is equal to h then we should make j  mid as
            // Now we want to get the value to be min and ans be equal to h.
            if(ans <= h)
                j = mid;
            else
                i = mid+1;
        }
        return j;
    }
};
