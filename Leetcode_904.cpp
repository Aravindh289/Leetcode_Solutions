class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> m;
        int r=0,l=0,n=fruits.size();
        int c=0,maxc=0;
        while(r<n)
        {
            m[fruits[r]]++;
            if(m.size()>2)
            {
                m[fruits[l]]--;
                if(m[fruits[l]] <= 0)
                    m.erase(fruits[l]);
                l++;
            }                
            c = abs(l-r)+1;
            maxc = max(maxc,c);
            r++;
        }
        return maxc;
    }
};