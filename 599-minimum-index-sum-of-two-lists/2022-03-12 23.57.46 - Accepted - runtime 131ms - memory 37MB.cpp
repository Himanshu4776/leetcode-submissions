class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        // Approach 1: Here we took an another hashmap for taking care of matching string index
//         unordered_map<string , int> mp;
//         map<int , vector<string>> temp;
//         vector<string> res;
//         for(int i = 0; i < list1.size(); i++){
//             mp[list1[i]] = i;
//         }
        
//         for(int j = 0; j < list2.size(); j++){
//             if(mp.find(list2[j]) != mp.end()) temp[j + mp[list2[j]]].push_back(list2[j]);
//         }
        
//         for(auto x : temp){
//             if(x.second.size() != 0){
//                 return x.second;
//             }
//         }
//         return {};
        
        
        // Approach 2: Here we will take a variable for finding the minimum index.
        vector<string> res;
        int indexSum = INT_MAX;
        unordered_map<string, int> mp;
        
        for(int i=0; i<list1.size(); i++) mp[list1[i]] = i;
        
        for(int i=0; i<list2.size(); i++)
        {
            if(mp.find(list2[i]) != mp.end())
            {   // String matched here in list1 and list2
                
                if(mp[list2[i]] + i < indexSum)
                {   // Here we will check for least index of that string
                    indexSum = mp[list2[i]] + i;
                    res.clear();
                    res.push_back(list2[i]);
                }
                else if(mp[list2[i]] + i == indexSum)
                    res.push_back(list2[i]);
            }    
        }
        
        return res;
    }
};