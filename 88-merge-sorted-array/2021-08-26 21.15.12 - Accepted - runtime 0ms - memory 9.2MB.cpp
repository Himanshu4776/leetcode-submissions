class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
        int i=m-1,j=n-1,k = n+m-1;
        n--;
        m--;
        
        while(i>=0 && j>=0)
        {
            if(n1[i] > n2[j])
            {
                n1[k] = n1[i];
                k--;
                i--;
            }
            else
            {
                n1[k] = n2[j];
                k--;
                j--;
            }
        }
        // now the whole comparable arrays are sorted now store the left arrays.
        while(i>=0)
        {
            n1[k--] = n1[i--]; 
        }
        while(j>=0)
        {
            n1[k--] = n2[j--];
        }
    }
    
};