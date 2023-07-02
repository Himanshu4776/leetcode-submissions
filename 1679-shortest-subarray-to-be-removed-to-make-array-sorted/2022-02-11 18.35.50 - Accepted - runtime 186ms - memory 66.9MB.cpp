class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), i;
        int back = n-1;
        int front = 0;
        while(front < n-1 && arr[front] <= arr[front+1]) front++;
        //If the array is completely sorted
        if (front == n-1)
            return 0;
        while(back >= front && arr[back] >= arr[back-1]) back--;
        //If the array is sorted completely in reverse order
        if (back == 0)
            return n - 1;

        // Now lets check the point where the problem lied in middle of array
        int res = min(n-1-front, back);
        i = 0;int j = back;
        while(i<=front && j<n)
        {
            if(arr[j] >= arr[i]){
                res = min(res,j-i-1);
                i++;
            }
            else
                j++;
        }
        return res;
    }
};