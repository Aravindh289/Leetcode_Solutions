class Solution {
public:
    int strStr(string haystack, string needle) {
        int txtsize = haystack.size();
        int ptnsize = needle.size();

        if (ptnsize == 0) return 0; 

        for (int i = 0; i <= txtsize - ptnsize; i++) {
            int j = 0;
            for (; j < ptnsize; j++) {
                if (haystack[i + j] != needle[j]) 
                    break;
            }
            if (j == ptnsize) 
                return i;
        }
        return -1;
    }
};
