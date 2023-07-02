class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int i=0,j=n-1;
        
        // what if array is already sorted.
        if(arr[i]<arr[j]) 
            return arr[0]; // return first element
        
        int temp;
        while(i<=j)
        {
            temp = (i+j)/2;
            if(arr[temp] > arr[j])
                i = temp+1;
            else if(arr[temp] < arr[j])
                j = temp;
            else j--;
        }
        return arr[temp];
    }
};