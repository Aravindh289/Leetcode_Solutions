class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream s(text);
        string word;
        map<char,int> bl = {};
        for(auto a:brokenLetters) bl[a]++;
        int c = 0,wc = 0;
        while(s >> word)
        {
            string cpy = word;
            map<char,int> m = {};
            for(auto a:cpy) m[a]++;
            wc++;
            for(auto a:bl)
            {
                if(m.find(a.first)!=m.end())
                {
                    c++;
                    break;
                }                  
            }
        }
        return wc-c;;
    }
};