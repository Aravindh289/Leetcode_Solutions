class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";
        if (n == 1) return strs[0];
        
        string a = strs[0];
        string b = strs[1];
        string prefix;
        
        for (int i = 0; i < min(a.size(), b.size()); i++) {
            if (a[i] == b[i])
                prefix += a[i];
            else
                break;
        }
        
        if (prefix.size() == 0) return "";
        
        for (int i = 2; i < n; i++) {
            string word = strs[i];
            int j = 0;
            while (j < prefix.size() && j < word.size() && prefix[j] == word[j])
                j++;
            prefix = prefix.substr(0, j);
            if (prefix.empty()) return "";
        }        
        return prefix;
    }
};
