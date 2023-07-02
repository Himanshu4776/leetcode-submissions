class Solution {
public:
    int solve(int heights[], int n) {
        int lt[n];
        lt[0] = -1;
        int rt[n];
        rt[n-1] = n;
        
        stack<int> st1;
        st1.push(0);
        for(int i=1;i<n;i++){
            while(!st1.empty() && heights[st1.top()] >= heights[i])
                st1.pop();
            
            if(st1.empty())
                lt[i] = -1;
            else
                lt[i] = st1.top();
            
            st1.push(i);
        }
        
        stack<int> st2;
        st2.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st2.empty() && heights[st2.top()] >= heights[i])
                st2.pop();
            
            if(st2.empty())
                rt[i] = n;
            else
                rt[i] = st2.top();
            
            st2.push(i);
        }
        
        int mx = -1;
        for(int i=0;i<n;i++){
            mx = max(mx, heights[i] * (rt[i] - lt[i] - 1));
        }
        return mx;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int v[m];
        for(int i=0;i<m;i++) v[i] = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == '0') v[j] = 0;
                else v[j]++;
            }
            int area = solve(v,m);
            ans = max(ans,area);
        }
        return ans;
    }
};