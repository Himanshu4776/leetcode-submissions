class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // if(s.size() != t.size())
        //     return false;
        // map<char,int>m1;
        // map<char,int>m2;
        // vector<int>v1;
        // vector<int>v2;
        // for(int a=0;a<s.size();a++)
        //     m1[s[a]]++;
        // for(int a=0;a<t.size();a++)
        //     m2[t[a]]++;
        // for(auto it:m1)
        //     v1.push_back(it.second);
        // // now we got the values of all chars repeattion values in s.
        // for(auto it:m2)
        //     v2.push_back(it.second);
        // // now we got the values of all chars repeattion values in s.
        // // lets check if the v1 and v2 are same. if yes then true else false.
        // sort(v1.begin(),v1.end());
        // sort(v2.begin(),v2.end());
        // int i=0,j=0;
        // while(i<s.size()-1)
        // {
        //     if(v1[i] == v2[j])
        //     {
        //         i++;j++;
        //     }
        //     else
        //         return false;
        // }
        // return true;   // timeout obtained
        
        // new approach:
     int sind[129] = {0}, tind[129] = {0};
    //hash tables for characters from our strings
      for(int i = 0; i < s.size(); i++)
      {
        if( sind[s[i]] != tind[t[i]] )// as every chars repeat will be same as t
            return false;             // watch egg , add. title , paper. 
        //if previous characters have different position
        sind[s[i]] = tind[t[i]] = i+1;//put last position of characters
      }
      return true;
    }
};