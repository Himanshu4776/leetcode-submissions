class Solution {
public:
    int compareVersion(string v1, string v2) {
        int res = 0,n1 = v1.size(),n2 = v2.size();
        int i = 0,j = 0,d = 0,s = 0;
        while(i<n1 || j<n2)
        {
            d = 0;s = 0;
            while(i<n1)
            {
                if(v1[i] != '.') {
                    d = d*10 + (v1[i] - '0');
                    i++;
                }
                else if(v1[i] == '.') break;
            }
            while(j<n2)
            {
                if(v2[j] != '.') {
                    s = s*10 + (v2[j] - '0');
                    j++;
                }
                else if(v2[j] == '.') break;
            }
            if(d > s) return 1;
            else if(d<s) return -1;
            i++;
            j++;
        }
        return res;
    }
};