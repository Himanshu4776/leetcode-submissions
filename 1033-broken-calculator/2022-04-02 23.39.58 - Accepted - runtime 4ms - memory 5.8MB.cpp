class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        
        while(target != startValue){
            if(startValue>target){
                ans+=(startValue-target);
                return ans;
            }
            
            else{
                if(target%2 == 0){
                    target/=2;
                }
                
                else{
                    target+=1;
                }
            }
            
            ans++;
        }
        
        return ans;
    }
};