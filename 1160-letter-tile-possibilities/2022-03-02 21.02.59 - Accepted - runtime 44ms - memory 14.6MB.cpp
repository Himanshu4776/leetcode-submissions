class Solution {
public:
    void solve(int pos,string tiles,unordered_set<string>&s)
    {
        int n = tiles.size();
        for(int i = pos;i<n;i++)
        {
            swap(tiles[i],tiles[pos]);
            s.insert(tiles.substr(0,pos+1));
            solve(pos+1,tiles,s);
            swap(tiles[pos],tiles[i]);
        }
    }
    
    int numTilePossibilities(string tiles) {
        unordered_set<string>s;
        solve(0,tiles,s);
        return s.size();
    }
};