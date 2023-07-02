class Solution {
public:
    // Map to get long url from short url.
    unordered_map<string,string>mp;
    // Map to get all values that can be inside the short modified url.
    unordered_map<string,int>cnt;
    
    // Generate random string
    string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string rstring()
    {
        string ans = "";
        for(int i = 0; i<8; i++)
        {
            ans+=str[rand()%62];
        }
        return ans;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string tmp=rstring();// Get the random generated string from function.
        // count that this random generated tmp string has been used once.
        cnt[tmp]+=1;
        mp[tmp+to_string(cnt[tmp])]=longUrl;
        // Now as it can used so add count of no of times this random string arrived.
        // map it to get origional string.
        return tmp+to_string(cnt[tmp]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
    
};
