class Solution {
    bool match(string &a,string &b){
        if(a.length() != b.length()) 
            return false;
        for(int i=0;i<a.length();i++)
            if(a.at(i) != b.at(i) && a.at(i) != '?' && b.at(i) != '?') 
                return false;
        return true;
    }
    bool allWild(string &s){
        for(int i=0;i<s.length();i++)
            if(s.at(i) != '?') 
                return false;
        return true;
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.length(), m = stamp.length();
        vector<int> ans;
        string str;
        bool foundMatch = true;
        
        // loop until no more reverse stamping can be done
        while(foundMatch)
        {   // Eachbtime we found the result. the loop will run one more time.
            foundMatch = false; // reset flag so that no infinite loop and ans will setup loop
            for(int i=0;i<n-m+1;i++)
            {
                str = target.substr(i,m);  // get substr of length m
                
                // if its all windcard no need to stamp
                if(allWild(str)) continue; 
                
                if(match(stamp,str))
                {  // match substr with stamp
                    foundMatch = true; // set flag
                    ans.push_back(i); // push the i as match is found
                    // replace all chars of str in target to '?'
                    for(int j=0;j<m;j++) target[i+j] = '?'; 
                }
            }
        }
        
        // base case
        if(!allWild(target))  ans.clear();
        if(ans.size() > 10*n) ans.clear();
        
        // reverse answer as we did the whole procedure in reverse
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};