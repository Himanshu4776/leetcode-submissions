class Solution {
public:
    int wateringPlants(vector<int>& arr, int c) {
        int n = arr.size();
        int steps = 0,cap = 0;
        for(int i=0;i<n;i++)
        {
            // only take those scenaros where the cap will be needed to fullfill.
            if(arr[i] > cap)
            {
                cap = c;
                steps += 2*i;
            }
            // now if cap is greater then it will fill and move one step ahead.
            steps++;
            // extra needed because we are starting from -1, it will be for other plats as well
            cap -= arr[i];
        }
        
        return steps;
    }
};