class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        int sum = 0;
        if(n == 0) return true;
        for(int i=0;i<l;i++)
        {
            if(flowerbed[i] == 0)
            {
                if((i>0 && flowerbed[i-1] == 1) || (i<(l-1) && flowerbed[i+1] == 1))
                    continue;
            
                flowerbed[i] = 1;
                sum++;
            }
            if(sum == n) return true;
        }
        return false;
    }
};