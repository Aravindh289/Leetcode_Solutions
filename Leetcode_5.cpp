class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string a = string(1,s[0]),ans="";
        for(int i=0;i<n;i++)
        {
            int l = i,r = i;
            string temp;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--,r++;
            }
            temp = s.substr(l+1,r-l+1-2);
            if(ans.size() < temp.size()) ans = temp;
            l = i, r = i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--,r++;
            }
            temp = s.substr(l+1,r-l+1-2);
            if(ans.size() < temp.size()) ans = temp;
        }
        return ans;
    }
};