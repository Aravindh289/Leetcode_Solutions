class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int bp = 0;
        map<char,int> m;
        for(int i=0;i<n;i++)
        {
            if(m.find(s[i])==m.end())
            {
                m[s[i]]++;
            }
            else
            {
                bp++;
                m.clear();
                m[s[i]]++;
            }
        }
        if(m.size() > 0) 
            return bp+1;
        return bp;
    }
};