class Solution {
public:
    int maxFreqSum(string s) {
        map<char, int> m;
        map<char, int> z;
        for (char c : s) 
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                m[c]++;
            }
            else
            {
                z[c]++;
            }
        }
        int c1=0,c2=0;
        for(auto a:m)
        {
            if(a.second>c1)
            {
                c1=a.second;
            }
        }
        for(auto a:z)
        {
            if(a.second>c2)
            {
                c2=a.second;
            }
        }
        return c1+c2;
    }
};
