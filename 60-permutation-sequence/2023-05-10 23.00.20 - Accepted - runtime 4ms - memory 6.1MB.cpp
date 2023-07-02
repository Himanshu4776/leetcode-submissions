class Solution {
public:
    string getPermutation(int n, int k) {
        // There are 2 solutions to this: 
        // 1) Using the next greater permutation approach:
        // void solve(string & s, int index, vector < string > & res) {
        //     if (index == s.size()) {
        //         res.push_back(s);
        //         return;
        //     }
        //     for (int i = index; i < s.size(); i++) {
        //         swap(s[i], s[index]);
        //         solve(s, index + 1, res);
        //         swap(s[i], s[index]);
        //     }
        //  }
        // string getPermutation(int n, int k) {
        //     string s;
        //     vector < string > res;
        //     for (int i = 1; i <= n; i++) {
        //         s.push_back(i + '0');
        //     }
        //     solve(s, 0, res);
        //     sort(res.begin(), res.end());
        //     
        //     make k 0-based indexed to point to kth sequence
        //     auto it = res.begin() + (k - 1);
        //     return *it;
        // }

        // Other solution is by mathematical calculation of permutations
        vector<int> nums;
        int factorial = 1;
        
        for(int i=1;i<n;i++) {
            nums.push_back(i);
            factorial = factorial*(i);
        }
        nums.push_back(n);
        string s = "";
        k-=1;
        // now we have got the num which will be at start position
        while(true) {
            s += nums[k/factorial] + '0';
            nums.erase(nums.begin()+k/factorial);
            // check if whole nums has been covered and removed or not if yes then break
            if(nums.size() == 0) break;
            k = k%factorial;
            factorial = factorial/nums.size();
        }
        return s;
    }
};