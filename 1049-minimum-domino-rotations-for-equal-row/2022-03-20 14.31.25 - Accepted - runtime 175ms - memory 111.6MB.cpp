class Solution {
private:
    int check(vector<int>&arr,int val,int n) {
        int res = 0;
        for(int i=0;i<n;i++) {
            if(arr[i] != val) res++;
        }
        return res;
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // unordered_map<int,int>m;
        // int n = tops.size(),num = 0,occr = 0;
        // if(n == 1) return 1;
        // for(int i=0;i<n;i++)
        // {
        //     if(tops[i] == bottoms[i]) {
        //         ++m[tops[i]];
        //         if(occr < m[tops[i]]) occr = m[tops[i]];
        //     }
        //     else {
        //         ++m[tops[i]];
        //         ++m[bottoms[i]];
        //         if(occr < m[tops[i]]) occr = m[tops[i]];
        //         if(occr < m[bottoms[i]]) occr = m[bottoms[i]];
        //     }
        // }
        // // cout<<occr<<endl;
        // // We have now got hashmap and the no with max freq.
        // // If this is the element whose occurence is same as length of array then
        // // We just need to return the check of that number in result
        // if(occr < n) return -1;
        // for(auto it:m) {
        //     if(it.second == occr){num = it.first; break;}
        // }
        // return min(check(tops,num,n),check(bottoms,num,n));
        
        int size = tops.size();
        if( size == 0 || size == 1) return -1;
        
        int common = -1;
        int num_1 = tops[0];
        int num_2 = bottoms[0];
        
        int num_1_count = 1;
        int num_2_count = 1;
        
        for(int i=1; i<size; i++){
            if(tops[i] == bottoms[i]){
                common = tops[i];
                break;
            }
            if(num_1 == tops[i] || num_1 == bottoms[i]) {
                common = num_1;
            }
            if(num_2 == tops[i] || num_2 == bottoms[i]){
                common = num_2;
            }
        }
        
        int flipped_to_top = 0;
        int flipped_to_bottom = 0;
        for(int i=0; i<size; i++){
            if(common != tops[i] && common != bottoms[i]) return -1;
            if(tops[i] == bottoms[i]) continue;
            if(tops[i] == common) 
                flipped_to_bottom++;
            else 
                flipped_to_top++;
        }
        
        if(flipped_to_bottom < flipped_to_top)
            return flipped_to_bottom;
        return flipped_to_top;
    }
};