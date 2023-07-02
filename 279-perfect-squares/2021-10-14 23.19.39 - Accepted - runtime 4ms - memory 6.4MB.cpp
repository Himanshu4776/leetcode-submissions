class Solution {
public:
    int numSquares(int n) {
        if(n<0)return 0;
        static vector<int> hg({0});
        while(hg.size()<=n)
        {
            int temp=INT_MAX;
            int m=hg.size();
            for(int i=1;i*i<=m;i++){
                temp=min(temp,hg[m-i*i]+1);
            }
            hg.push_back(temp);
        }
        return hg[n];
    }
};