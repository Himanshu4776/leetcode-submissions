class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        priority_queue<pair<int,char>>max_heap;
        for(auto &[ch,freq]:mp){
            max_heap.push({freq,ch});
        }
        string ans;
        while(max_heap.size()>=2){
            auto [freq1,str1]=max_heap.top();
            max_heap.pop();
            auto [freq2,str2]=max_heap.top();
            max_heap.pop();
            ans+=str1;
            ans+=str2;
            if(--freq1>0) max_heap.push({freq1,str1});
            if(--freq2>0) max_heap.push({freq2,str2});
        }
        if(!max_heap.empty()){
            auto [freq,str]=max_heap.top();
            if(freq>1) return ans="";
            ans+=str;
        }
        return ans;

    }
};

// example:
// i/p:
// aaaaaa bbb cd e f
// o/p:
// 4 1 1 1 1 1
// abababadaeaf