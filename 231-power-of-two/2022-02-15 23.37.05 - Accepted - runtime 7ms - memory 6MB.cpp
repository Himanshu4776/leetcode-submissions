class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool flag = false;
        for(int i=0;pow(2,i)<=n;i++)
        {
            if(pow(2,i) == n)
            {
                flag = true;
                break;
            }
        }
        return flag;
    }
};