class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> m;
        for(auto a:nums) m[a]++;
        int maxx = -1;
        for(auto a:m)
           maxx = max(maxx,a.second);
        int c=0;
        for(auto a:m)
        {
            if(maxx == a.second) c++;
        }
        return maxx*c;
    }
};