class Solution {
public:
    bool doesAliceWin(string s) {
        int vwl = 0;
        for(auto x:s)
        {
           if(x == 'a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x =='E' || x=='I'
           || x=='O' || x=='U')
           {
                return true;
           }
        }
        return false;
    }
};