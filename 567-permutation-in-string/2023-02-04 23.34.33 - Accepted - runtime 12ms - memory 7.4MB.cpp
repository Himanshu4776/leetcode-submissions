class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i,n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2) return false;
        vector<int>v1(26,0),v2(26,0);

        for(i=0;i<n1;i++){
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }
        if(v1 == v2) return true;
        // means if both s1 and s2 are same then it should be correct
        int start = 0,end = i;
        
        while(end < n2) {
            // now elements to add remove prev one to move the window
            --v2[s2[start] - 'a'];
            ++v2[s2[end] - 'a'];
            if(v2 == v1) return true;
            
            start++;end++;
        }
        return false;
    }
};