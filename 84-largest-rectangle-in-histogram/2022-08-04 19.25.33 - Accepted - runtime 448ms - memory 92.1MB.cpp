class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<pair<int,int>>st,st2;
        vector<int>left,right;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            if(st.empty()) {
                left.push_back(-1);
            }
            else if(!st.empty() && st.top().first < arr[i]) {
                left.push_back(st.top().second);
            }
            else {
                while(!st.empty() && st.top().first >= arr[i]) st.pop();
                if(st.size() == 0) left.push_back(-1);
                else left.push_back(st.top().second);
            }
            st.push({arr[i],i});
        }
        // Now we have the left array containing nearest left small element
        for(int i=n-1;i>=0;i--)
        {
            if(st2.empty()) right.push_back(n);
            else if(!st2.empty() && st2.top().first < arr[i]) {
                right.push_back(st2.top().second);
            }
            else {
                while(!st2.empty() && st2.top().first >= arr[i]) st2.pop();
                if(st2.size() == 0) right.push_back(n);
                else right.push_back(st2.top().second);
            }
            st2.push({arr[i],i});
        }
        reverse(right.begin(),right.end());
        // Now we right smallest element as well 
        // lets findout the width of rectangle as height we already know.
        int maxval = INT_MIN;
        for(int i=0;i<n;i++) {
            maxval = max(maxval,(right[i]-left[i]-1)*arr[i]);
        }
        return maxval;
    }
};