class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> v;
        int c = 0;
        for(int i=0;i<spells.size();i++)
        {
            c=0;
            for(int j=0;j<potions.size();j++)
            {
                if(1LL*spells[i]*potions[j] >= success)
                    c++;
            }
            v.push_back(c);
        }
        return v;
    }
};
//the brute force approach ill reach TLE,so the optimal approach
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> v;
        int c = 0;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++)
        {
            c=0;
            int n = potions.size();
            int l = 0,r = n-1;
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(1LL*spells[i]*potions[mid] >= success)
                {
                    c += (r-mid)+1;
                    r = mid-1;
                }
                else if(1LL*spells[i]*potions[mid] > success)
                {
                    r = mid-1;
                }
                else
                    l = mid+1;
            }
            v.push_back(c);
        }
        return v;
    }
};
