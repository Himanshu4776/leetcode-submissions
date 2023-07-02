class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n =  arr.size();
        map<int,int>m;
        priority_queue<int> pq;
        int ans = 0,count = 0;
        
        for(int i=0;i<n;i++) m[arr[i]]++;
        for(auto it:m) pq.push(it.second);
        
        // Now iterate for the max occurence elements and pop them 
        // and check for count and ans
        while(!pq.empty()) {
            count += pq.top();
            ans++;
            if(count >= n/2) break;
            pq.pop();
        }
        return ans;
    }
};