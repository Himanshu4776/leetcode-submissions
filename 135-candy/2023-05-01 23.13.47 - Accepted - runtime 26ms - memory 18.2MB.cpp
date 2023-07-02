class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>leftToright(n,1);
        vector<int>rightToleft(n,1);
        int ans = 0;
        
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                leftToright[i] += leftToright[i-1];
            }
        }
        for(int i=n-2;i>=0;i--) {
            if(ratings[i]>ratings[i+1]) {
                rightToleft[i] += rightToleft[i+1];
            }
        }
        for(int i=0;i<n;i++) {
            ans += max(leftToright[i], rightToleft[i]);
        }
        return ans;
    }
};