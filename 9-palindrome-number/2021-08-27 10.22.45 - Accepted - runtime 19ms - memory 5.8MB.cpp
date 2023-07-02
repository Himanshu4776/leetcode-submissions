class Solution {
public:
    bool isPalindrome(int x) {
        int val = 0;
        int pal = x;
        bool answer = false;
        // if(x<0 || (x!=0 && x%10==0))
        //     return false;
        while(x!=0 && abs(val) < INT_MAX/10)
        {
            val = val*10 + x%10;
            x = x/10;
        }
        if(val>=0)
        {
            if(pal==val)
                answer = true;
            else
                answer = false;
        }
        return answer;
    }
};