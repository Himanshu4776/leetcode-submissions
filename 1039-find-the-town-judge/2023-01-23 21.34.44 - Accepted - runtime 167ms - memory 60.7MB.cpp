class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int judge = -1,m = trust.size();
        vector<int>arr(n+1);
        //just like hashmap do increment the trust for the person whom ai trust
        // and decrement the trust for otherones. so at last if we get arr array
        // have someone with value n-1 then that's our answer.
        for(int i=0;i<m;i++)
        {
            arr[trust[i][0]] -= 1;
            arr[trust[i][1]] += 1;
        }
        for(int i=1;i<=n;i++)
        {
            if(arr[i] == n-1)
                return i;
        }
        
        //This approach reuires sorting on 1st value.
        // before this make a custom sort. To sort them.
        // for(int i =0;i<m-1;i++)
        // {
        //     if(trust[i][1] != trust[i+1][1])
        //     {
        //         flag = 1;
        //         break;
        //     }
        // }
        // if(flag == 0)
        // {
        //     judge = trust[0][1];
        // }
        return judge;
    }
};