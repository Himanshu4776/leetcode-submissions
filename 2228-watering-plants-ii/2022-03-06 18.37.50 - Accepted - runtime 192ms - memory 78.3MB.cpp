class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
		int A=capacityA,B=capacityB;
        int i=0,j=plants.size()-1;
        int refill=0;
        while(i<j)
        {
            if(plants[i]>A){
                refill++;
                A=capacityA;
            }
            if(plants[j]>B){
                refill++;
                B=capacityB;
            }
            A-=plants[i++];
            B-=plants[j--];
        }
        // when they are about to water the same plant
        if(i==j)
        {
            if(A>=B)
            {
                if(plants[i]>A){
                    refill++;
                    A=capacityA;
                }
                A-=plants[i++];
            }
            else
            {
                if(plants[j]>B){
                    refill++;
                    B=capacityB;
                }
                B-=plants[j--];
            }
        }
        return refill;
    }
};