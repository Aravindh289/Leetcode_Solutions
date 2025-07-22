class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ss;
        int l=0,r=0,max_length=0,len=0;
        while(r<s.size())
        {
           if(ss.count(s[r]))
           { 
               len--;
               ss.erase(s[l]);
               l++; 
           }
           else
           {
            ss.insert(s[r]);
            r++;
            len++;
            max_length=max(len,max_length);
           }
        }
        return max_length;
    }
};
