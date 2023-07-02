class Solution {
private:
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
public:
    bool canMeasureWater(int jug1, int jug2, int targetCapacity) {
        int val = jug1 + jug2;
        if( targetCapacity > val) return false;
        if(targetCapacity%gcd(jug1,jug2) == 0) return true;
        
        return false;
    }
};