class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n,'a');
        k -= n;// as we have already placed 'a' at all n places.
        // so now max we can add 25 there.
        // we want to create the string as aaa...some mid char...zzzzz;
        // like this so it would be lexograhic string now.
        
        // Lets traverse form right end with i;
        int i=n-1;
        while(k)
        {
            res[i] += min(k,25);
            k -= min(k,25);
            
            i--;
        }
        return res;
    }
};