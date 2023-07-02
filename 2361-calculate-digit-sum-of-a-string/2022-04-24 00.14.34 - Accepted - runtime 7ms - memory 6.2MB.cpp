class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size() <= k) return s;
        string ans = "",val = "";
        int count = 0,sum = 0;
        vector<int>sol;
        while(s.size()>k)
        {
            sol.clear();
            for(int i=0;i<s.size();i++) {
                // val += s[i];
                sum += s[i] - '0';
                count += 1;
                if(count == k) {
                    sol.push_back(sum);
                    // cout<<sum<<" ";
                    count = 0;
                    sum = 0;
                }
            }
            if(count != 0) {
                sol.push_back(sum);
                // cout<<sum<<" ";
                sum = 0;
                count = 0;
            }
            for(int j=0;j<sol.size();j++){
                ans += to_string(sol[j]);
            }
            s = ans;
            // cout<<endl;
            ans = "";
            // cout<<"new string: "<<s<<endl;
        }
        return s;
    }
};