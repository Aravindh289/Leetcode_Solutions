class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n<k) 
           return false;
        if(n==k)
            return true;
        map<char,int> m;
        for(char c:s)
        {
            m[c]+=1;
        }
        int c=0;
        for(auto a:m)
        {
            if(a.second%2 == 1)
                 c+=1;
        }
        return c<=k?true:false;
    }
};