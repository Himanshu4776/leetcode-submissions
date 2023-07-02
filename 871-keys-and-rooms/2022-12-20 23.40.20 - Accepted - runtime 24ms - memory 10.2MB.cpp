class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> found(n,false);
        found[0] =true;
        stack<int> toVisit;
        toVisit.push(0);
        
        while(!toVisit.empty()){
            int room = toVisit.top();
            toVisit.pop();
            for(auto n:rooms[room]){
                if(found[n]==false)
                {
                    found[n]=true;
                    toVisit.push(n);
                }
            }
        }
        
        //check we reach all rooms
        for(auto room:found){
            if(room==false)
                return false;
        }
        return true;
    }
};