class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& vans) {
        // int n = a.size();
        // long long int ans = mass;
        // sort(a.begin(),a.end());
        // for(int v:a)
        // {
        //     if(v>ans) return false;
        //     else ans += v;
        // }
        // return true;
        ios::sync_with_stdio(false);
        cin.tie(0);
        int arr[100001]={0};
        int maxi = 0;
        for(auto &i:vans){
            arr[i]++;
            maxi=max(maxi,i);
        }
        if(mass>maxi)
            return true;
        long long ans = mass;
        for(int i = 0 ; i < 100001 ; i++){
            if(arr[i]==0)
                continue;
            if(i>ans)
                return false;
            ans+=(long long)arr[i]*i;
            if(ans>maxi)
                return true;
        }
        return true;
    }
};