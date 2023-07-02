class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int count = 0;
        vector<string>ans;
        int i=1;
        while(i<=n)
        {
            if(count == target.size())
                break;
            
            if(target[count] == i)
            {
                ans.push_back("Push");
                count++;
                i++;
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }
        }
        return ans;
    }
};