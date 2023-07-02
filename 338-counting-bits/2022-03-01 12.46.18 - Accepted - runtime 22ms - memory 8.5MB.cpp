class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>result;
        for(int i=0;i<=num;i++)
        {
            int n = i;
            int counter =0;
            while(n!=0)
            {
                if(n&1 == 1)
                    counter++;

                n = n/2;
            }
            result.push_back(counter);
        }
        return result;
    }
};