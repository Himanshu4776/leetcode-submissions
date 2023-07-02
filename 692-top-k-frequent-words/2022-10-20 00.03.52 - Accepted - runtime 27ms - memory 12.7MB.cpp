class Solution {
public:
    bool static compare(pair<int,string>& a , pair<int,string>& b){
        if(a.first>b.first)
            return true;
        else if(a.first==b.first){
            if(a.second<b.second)
                return true;
            else
                return false;
        }
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> um;
        for(auto st : words) {
            um[st]++;
        }
        vector<pair<int, string>> pq;
        for( auto it : um) {
            pq.push_back({it.second , it.first});
        }
        sort(pq.begin() ,pq.end() , compare);
        vector<string> result(k);
        for(int i=0;i<k;i++) { 
            result[i]= pq[i].second;
        }
        return result;
    }
};