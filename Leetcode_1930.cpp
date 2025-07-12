class Solution 
{
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        unordered_map<char,pair<int,int>> oc;
        for(int i=0;i<n;++i)
        {
            if(!oc.count(s[i]))
                oc[s[i]].first = oc[s[i]].second = i;
            else
                oc[s[i]].second = i;
        }
        int count=0;
        for(auto [c,se]: oc)
        {
            if(se.first==se.second) continue;
            count += unordered_set<char>(s.begin()+se.first+1, s.begin()+se.second).size();
        }
        return count;
    }
};