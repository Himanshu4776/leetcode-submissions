class Solution {
public:
    pair<pair<int,int>,pair<int,int>> get(vector<pair<int,int>> &nums){
    pair<int,int> p, q;
   
    for(auto i:nums){
        if(p.first<i.first) q=p, p=i;
        else if(q.first<i.first and i!=p) q=i;
    }
    return {p,q};
}

int minimumOperations(vector<int>& nums) {
    int n= size(nums);
	//count of even and odd places
    int p_e=0,p_o=0;
	
	int mx= *max_element(begin(nums),end(nums));
	
	//vector of pairs representing {count, element value}
    vector<pair<int,int>> even(mx+1),odd(mx+1);
	
	int k=0;
	
    //get count of all elements along with their count
    for(auto i:nums){
        //even index
        if(k%2==0){
           even[i].first++, even[i].second=i, p_e++; 
        }
        else{
           odd[i].first++, odd[i].second=i, p_o++; 
        }
		k++;
    }
    
    auto p= get(odd);
    auto q= get(even);
	
    if(q.first.second!=p.first.second) return (p_e- q.first.first)+(p_o-p.first.first);
    
    int x= (p_e-q.first.first) + (p_o-p.second.first);
    int y= (p_e-q.second.first) + (p_o-p.first.first);
    
    return min(x,y);
}
};