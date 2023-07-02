class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // int ans = 0,n = colors.size();
        // if(n == 1) return 0;
        // int i=1, j =0;
        // for(i=1;i<n;i++)
        // {
        //     if(colors[i] == colors[j]) {
        //         if(neededTime[i] >= neededTime[j]) {
        //             ans += min(neededTime[i],neededTime[j]);
        //             j++;
        //         }
        //         else {
        //             ans += min(neededTime[i],neededTime[j]);
        //         }
        //     }
        //     else {
        //         j++;
        //     }
        // }
        // return ans;
        
        
        // better approach using kadane's algo:
        // totalTime: total time needed to make rope colorful;
        // currMaxTime: maximum time of a balloon needed in this group.
        int totalTime = 0, currMaxTime = 0;
        
        for (int i = 0; i < colors.size(); ++i) {
            // If this balloon is the first balloon of a new group
            // set the currMaxTime as 0.
            if (i > 0 && colors[i] != colors[i - 1]) {
                currMaxTime = 0;
            }
            
            // Increment totalTime by the smaller one.
            // Update currMaxTime as the larger one.
            totalTime += min(currMaxTime, neededTime[i]);
            currMaxTime = max(currMaxTime, neededTime[i]);
        }
        
        return totalTime;
    }
};