class Solution {
public:
    bool judgeCircle(string m) {
        int h = 0,v = 0;
        bool flag = false;
        for(char ch:m)
        {
            switch(ch)
            {
                case 'U': v++;
                break;
                case 'D' : v--;
                break;
                case 'L' : h--;
                break;
                case 'R' : h++;
                break;
            }
        }
        if(h==0 && v==0)
            flag = true;
        // cout<<v<<" "<<h;
        return flag;
    }
};